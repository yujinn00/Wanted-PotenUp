#pragma once

#include <vector>

#include "Node.h"

// 쿼드 트리 클래스.
class QuadTree  
{
public:
    QuadTree(const Bounds& bounds);
    ~QuadTree();

    // 쿼드 트리에 점을 추가할 때 사용하는 함수.
    // 내부에서는 루트 노드에서부터 재귀적으로 추가.
    void Insert(Node* node);

    // 전달한 노드와 겹치는 노드를 반환하는 함수.
    std::vector<Node*> Query(Node* queryNode);

public:
    // 나눌 수 있는 트리의 최대 깊이.
    // const 키워드는 헤더 파일에 선언 및 정의.
    static const int maxDepth = 4;

private:
    Node* root = nullptr;
};
