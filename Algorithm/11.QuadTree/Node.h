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

// 영역 구분을 위한 열거형.
enum class NodeIndex
{
    TopLeft,        // 경계선에 걸치지 않고 완전 포함.
    TopRight,
    BottomRight,
    BottomLeft,
    Straddling,     // 경계선에 걸친 경우.
    OutOfArea       // 영역을 벗어난 경우.
};

// 쿼드 트리 노드 클래스
class QuadTree;
class Node
{
public:
    Node(const Bounds& bounds, int depth = 0);
    ~Node();

    // 삽입.
    void Insert(Node* node);

    // 질의.
    void Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes);

    // 정리.
    void Clear();

    // Getter.
    // 현재 노드의 영역.
    Bounds GetBounds() const { return bounds; }

    // 현재 영역에 포함된 노드.
    std::vector<Node*>& Points() { return points; }

    // 자식 노드.
    Node* TopLeft() const { return topLeft; }
    Node* TopRight() const { return topRight; }
    Node* BottomLeft() const { return bottomLeft; }
    Node* BottomRight() const { return bottomRight; }

private:
    // 영역을 사분할할 때 사용하는 함수.
    bool Subdivide();

    // 영역이 분할됐는지 확인하는 함수.
    bool IsDivided();

    // 자식 노드 정리 함수.
    void ClearChildren();

    // 전달한 영역과 겹치는 영역을 반환하는 함수.
    NodeIndex TestRegion(const Bounds& bounds);

    // 전달한 영역이 포함되거나 겹치는 영역을 모두 구할 때, 사용하는 함수.
    std::vector<NodeIndex> GetQuads(const Bounds& bounds);

private:
    // 현재 노드의 깊이.
    int depth = 0;

    // 현재 노드의 영역.
    Bounds bounds;

    // 현재 영역에 포함된 노드.
    std::vector<Node*> points;

    // 자식 노드.
    Node* topLeft = nullptr;
    Node* topRight = nullptr;
    Node* bottomLeft = nullptr;
    Node* bottomRight = nullptr;
};
