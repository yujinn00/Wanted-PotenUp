#include "QuadTree.h"

QuadTree::QuadTree(const Bounds& bounds)
{
    // 루트 노드 생성.
    root = new Node(bounds);
}

QuadTree::~QuadTree()
{
    // 루트 노드 삭제.
    SafeDelete(root);
}

void QuadTree::Insert(Node* node)
{
    root->Insert(node);
}

std::vector<Node*> QuadTree::Query(Node* queryNode)
{
    // 겹침 가능성이 있는 영역 확인.
    std::vector<Node*> possibleNodes;
    root->Query(queryNode->GetBounds(), possibleNodes);

    // 겹침 가능성이 있는 노드에서 실제로 겹치는 노드를만 다시 검사.
    std::vector<Node*> intersects;
    for (Node* node : possibleNodes)
    {
        // 가능성 있는 영역 포함된 노드 순회.
        for (Node* point : node->Points())
        {
            // 해당 노드와 전달된 노드의 영역 겹침 테스트.
            if (point->GetBounds().Intersects(queryNode->GetBounds()))
            {
                intersects.emplace_back(point);
                // continue 붙이나 안 붙이나 차이가 나는지,
                // 잘은 모르겠지만 우선 붙여볼 것임.
                continue;
            }
        }
    }

    // 검사한 결과를 반환.
    return intersects;
}
