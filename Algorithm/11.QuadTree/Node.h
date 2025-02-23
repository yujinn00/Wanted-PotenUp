#pragma once

#include <vector>

#include "Bounds.h"

template<typename T>
void SafeDelete(T*& t)
{
    if (t)
    {
        delete t;
        t = nullptr;
    }
}

// Ư�� ��尡 ��� ����(��и�)�� ���ϴ��� ��Ÿ���� ������.
enum class NodeIndex
{
    TopLeft,        // ������ ��輱�� �������� �ʰ�, ������ ���� ���Ե� ���.
    TopRight,
    BottomLeft,
    BottomRight,
    Straddling,     // ������ ��輱�� ������ ���.
    OutOfArea       // ������ ��� ���.
};

// ���� Ʈ�� ��� Ŭ����.
class QuadTree;
class Node
{
public:
    Node(const Bounds& bounds, int depth = 0);
    ~Node();

    // ����.
    void Insert(Node* node);

    // ����.
    // possibleNodes: ��ġ�� ��带 �����ϱ� ���� ����.
    void Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes);

    // ����.
    void Clear();

    // Getter.
    // ���� ����� ����.
    Bounds GetBounds() const { return bounds; }

    // ���� ������ ���Ե� ���.
    // ����Ʈ != ��.
    std::vector<Node*>& Points() { return points; }

    // �ڽ� ���.
    Node* TopLeft() const { return topLeft; }
    Node* TopRight() const { return topRight; }
    Node* BottomLeft() const { return bottomLeft; }
    Node* BottomRight() const { return bottomRight; }

private:
    // ������ ������� �� ����ϴ� �Լ�.
    bool Subdivide();

    // ������ ���ҵƴ��� Ȯ���ϴ� �Լ�.
    bool IsDivided();

    // �ڽ� ��� ���� �Լ�.
    void ClearChildren();

    // ������ ������ �����ϴ� ������ ��ȯ�ϴ� �Լ�.
    // ��ȯ���� ���� ��� ��и鿡 ���ϴ��� �Ǻ�.
    NodeIndex TestRegion(const Bounds& bounds);

    // ������ ������ �����ϴ� ������ ���� ���ԵǴ� ������ ��� ���� ��, ����ϴ� �Լ�.
    // ���� Straddling�̸� ���� ��и��� ��ȯ.
    std::vector<NodeIndex> GetQuads(const Bounds& bounds);

private:
    // ���� ����� ����.
    int depth = 0;

    // ���� ����� ����.
    Bounds bounds;

    // ���� ������ ���Ե� ���.
    // ����Ʈ != ��.
    std::vector<Node*> points;

    // �ڽ� ���.
    Node* topLeft = nullptr;
    Node* topRight = nullptr;
    Node* bottomLeft = nullptr;
    Node* bottomRight = nullptr;
};
