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

// 특정 노드가 어느 영역(사분면)에 속하는지 나타내는 열거형.
enum class NodeIndex
{
    TopLeft,        // 영역의 경계선과 교차하지 않고, 영역에 완전 포함된 경우.
    TopRight,
    BottomLeft,
    BottomRight,
    Straddling,     // 영역의 경계선과 교차한 경우.
    OutOfArea       // 영역을 벗어난 경우.
};

// 쿼드 트리 노드 클래스.
class QuadTree;
class Node
{
public:
    Node(const Bounds& bounds, int depth = 0);
    ~Node();

    // 삽입.
    void Insert(Node* node);

    // 질의.
    // possibleNodes: 겹치는 노드를 저장하기 위한 벡터.
    void Query(const Bounds& queryBounds, std::vector<Node*>& possibleNodes);

    // 정리.
    void Clear();

    // Getter.
    // 현재 노드의 영역.
    Bounds GetBounds() const { return bounds; }

    // 현재 영역에 포함된 노드.
    // 포인트 != 점.
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

    // 전달한 영역과 교차하는 영역을 반환하는 함수.
    // 반환값을 통해 어느 사분면에 속하는지 판별.
    NodeIndex TestRegion(const Bounds& bounds);

    // 전달한 영역과 교차하는 영역과 완전 포함되는 영역을 모두 구할 때, 사용하는 함수.
    // 만약 Straddling이면 여러 사분면이 반환.
    std::vector<NodeIndex> GetQuads(const Bounds& bounds);

private:
    // 현재 노드의 깊이.
    int depth = 0;

    // 현재 노드의 영역.
    Bounds bounds;

    // 현재 영역에 포함된 노드.
    // 포인트 != 점.
    std::vector<Node*> points;

    // 자식 노드.
    Node* topLeft = nullptr;
    Node* topRight = nullptr;
    Node* bottomLeft = nullptr;
    Node* bottomRight = nullptr;
};
