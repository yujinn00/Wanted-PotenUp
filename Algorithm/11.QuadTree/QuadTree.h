#pragma once

#include <vector>

#include "Node.h"

// ���� Ʈ�� Ŭ����.
class QuadTree  
{
public:
    QuadTree(const Bounds& bounds);
    ~QuadTree();

    // ���� Ʈ���� ���� �߰��� �� ����ϴ� �Լ�.
    // ���ο����� ��Ʈ ��忡������ ��������� �߰�.
    void Insert(Node* node);

    // ������ ���� ��ġ�� ��带 ��ȯ�ϴ� �Լ�.
    std::vector<Node*> Query(Node* queryNode);

public:
    // ���� �� �ִ� Ʈ���� �ִ� ����.
    // const Ű����� ��� ���Ͽ� ���� �� ����.
    static const int maxDepth = 4;

private:
    Node* root = nullptr;
};
