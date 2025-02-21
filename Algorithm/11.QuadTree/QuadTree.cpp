#include "QuadTree.h"

QuadTree::QuadTree(const Bounds& bounds)
{
    // ��Ʈ ��� ����.
    root = new Node(bounds);
}

QuadTree::~QuadTree()
{
    // ��Ʈ ��� ����.
    SafeDelete(root);
}

void QuadTree::Insert(Node* node)
{
    root->Insert(node);
}

std::vector<Node*> QuadTree::Query(Node* queryNode)
{
    // ��ħ ���ɼ��� �ִ� ���� Ȯ��.
    std::vector<Node*> possibleNodes;
    root->Query(queryNode->GetBounds(), possibleNodes);

    // ��ħ ���ɼ��� �ִ� ��忡�� ������ ��ġ�� ��带�� �ٽ� �˻�.
    std::vector<Node*> intersects;
    for (Node* node : possibleNodes)
    {
        // ���ɼ� �ִ� ���� ���Ե� ��� ��ȸ.
        for (Node* point : node->Points())
        {
            // �ش� ���� ���޵� ����� ���� ��ħ �׽�Ʈ.
            if (point->GetBounds().Intersects(queryNode->GetBounds()))
            {
                intersects.emplace_back(point);
                // continue ���̳� �� ���̳� ���̰� ������,
                // ���� �𸣰����� �켱 �ٿ��� ����.
                continue;
            }
        }
    }

    // �˻��� ����� ��ȯ.
    return intersects;
}
