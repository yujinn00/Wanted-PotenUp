#include "Node.h"
#include "QuadTree.h"

Node::Node(const Bounds& bounds, int depth)
    : bounds(bounds), depth(depth)
{
}

Node::~Node()
{
    Clear();
}

void Node::Insert(Node* node)
{
    // 겹치는 영역 확인.
    NodeIndex result = TestRegion(node->GetBounds());

    // 겹치는 경우, 현재 노드에 추가.
    if (result == NodeIndex::Straddling)
    {
        points.emplace_back(node);
    }

    // 겹치지 않는 경우, 분할하고 자식 노드에 추가.
    else if (result != NodeIndex::OutOfArea)
    {
        if (Subdivide())
        {
            if (result == NodeIndex::TopLeft)
            {
                topLeft->Insert(node);
            }
            else if (result == NodeIndex::TopRight)
            {
                topRight->Insert(node);
            }
            else if (result == NodeIndex::BottomLeft)
            {
                bottomLeft->Insert(node);
            }
            else if (result == NodeIndex::BottomRight)
            {
                bottomRight->Insert(node);
            }
        }

        // 더 이상 분할할 수 없는 경우, 현재 노드에 추가.
        else
        {
            points.emplace_back(node);
        }
    }
}

// 재귀를 통해, 참조로 받은 possibleNodes를 계속해서 갱신.
// 참고) Node 클래스의 Query 함수는 겹칠 가능성이 있는 노드들을 먼저 탐색하여 결과 리스트에 추가하는 함수.
void Node::Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes)
{
    // 현재 노드 추가.
    possibleNodes.emplace_back(this);

    // 영역이 분할된 경우, 자식 노드에 대해 추가 검사.
    if (IsDivided())
    {
        // 전달 받은 영역과 겹치는 사분면 목록 확인.
        std::vector<NodeIndex> quads = GetQuads(queryBounds);

        // 겹치는 사분면을 기준으로 검사 진행 (재귀).
        for (NodeIndex& index : quads)
        {
            if (index == NodeIndex::TopLeft)
            {
                topLeft->Query(queryBounds, possibleNodes);
            }
            else if (index == NodeIndex::TopRight)
            {
                topRight->Query(queryBounds, possibleNodes);
            }
            else if (index == NodeIndex::BottomLeft)
            {
                bottomLeft->Query(queryBounds, possibleNodes);
            }
            else if (index == NodeIndex::BottomRight)
            {
                bottomRight->Query(queryBounds, possibleNodes);
            }
        }
    }
}

bool Node::Subdivide()
{
    // 트리에서 지정한 최대 깊이에 도달하면 더 이상 나누지 않음.
    if (depth == QuadTree::maxDepth)
    {
        return false;
    }

    // 아직 분할하지 않은 경우, 4개의 자식 노드로 분할.
    if (!IsDivided())
    {
        // 영역을 나누기 위한 값 계산.
        float x = bounds.X();
        float y = bounds.Y();
        float halfWidth = bounds.Width() / 2.0f;
        float halfHeight = bounds.Height() / 2.0f;

        // 각 사분면에 해당하는 자식 노드 생성.
        topLeft = new Node(Bounds(x, y, halfWidth, halfHeight), depth + 1);
        topRight = new Node(Bounds(x + halfWidth, y, halfWidth, halfHeight), depth + 1);
        bottomLeft = new Node(Bounds(x, y + halfHeight, halfWidth, halfHeight), depth + 1);
        bottomRight = new Node(Bounds(x + halfWidth, y + halfHeight, halfWidth, halfHeight), depth + 1);
    }

    return true;
}

bool Node::IsDivided()
{
    // 사분면의 자식 객체가 널 값인지 확인.
    // topLeft만 확인해도 나머지 3개의 노드도 존재한다고 간주할 수 있음.
    return topLeft != nullptr;
}

void Node::ClearChildren()
{
    // 분할이 진행된 경우, 자식 노드를 정리.
    if (IsDivided())
    {
        SafeDelete(topLeft);
        SafeDelete(topRight);
        SafeDelete(bottomLeft);
        SafeDelete(bottomRight);
    }
}

void Node::Clear()
{
    // 현재 노드 제거.
    for (Node* node : points)
    {
        SafeDelete(node);
    }

    // 리스트 초기화.
    points.clear();

    // 분할된 경우, 자식 정리.
    if (IsDivided())
    {
        topLeft->Clear();
        topRight->Clear();
        bottomLeft->Clear();
        bottomRight->Clear();

        ClearChildren();
    }
}

NodeIndex Node::TestRegion(const Bounds& bounds)
{
    // 전달된 bounds와 겹치는 사분면 목록 확인.
    std::vector<NodeIndex> quads = GetQuads(bounds);

    // 겹치는 곳이 없으면 영역 밖으로 표시.
    if (quads.size() == 0)
    {
        return NodeIndex::OutOfArea;
    }

    // 하나의 사분면만 겹치는 경우, 해당 사분면 반환.
    if (quads.size() == 1)
    {
        return quads[0];
    }

    // 여러 사분면과 겹치는 경우, 겹친 상태 반환.
    return NodeIndex::Straddling;
}

std::vector<NodeIndex> Node::GetQuads(const Bounds& bounds)
{
    std::vector<NodeIndex> quads;

    // 영역 계산에 필요한 변수 설정.
    float x = this->bounds.X();
    float y = this->bounds.Y();
    float halfWidth = this->bounds.Width() / 2.0f;
    float halfHeight = this->bounds.Height() / 2.0f;
    float centerX = x + halfWidth;
    float centerY = y + halfHeight;

    // 아래 네 가지 경우, 꽤 어려웠음 => 직접 그려서 확인함.
    // 최소와 최대를 잘 설정하면, 겹치는지 확인이 가능함.
    // 진짜 어려웠으니 .. 잘 기억하면 좋겠다.
    // 왼쪽 영역에 겹치는지 확인.
    bool left = bounds.X() < centerX && bounds.MaxX() >= x;

    // 오른쪽 영역에 겹치는지 확인.
    bool right = bounds.MaxX() >= centerX && bounds.X() < x + this->bounds.MaxX();

    // 위쪽 영역에 겹치는지 확인.
    bool top = bounds.Y() < centerY && bounds.MaxY() >= y;

    // 아래쪽 영역에 겹치는지 확인.
    bool bottom = bounds.MaxY() >= centerY && bounds.Y() < y + this->bounds.MaxY();

    if (top && left)
    {
        quads.emplace_back(NodeIndex::TopLeft);
    }
    if (top && right)
    {
        quads.emplace_back(NodeIndex::TopRight);
    }
    if (bottom && left)
    {
        quads.emplace_back(NodeIndex::BottomLeft);
    }
    if (bottom && right)
    {
        quads.emplace_back(NodeIndex::BottomRight);
    }

    return quads;
}
