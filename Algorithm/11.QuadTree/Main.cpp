#include <iostream>

#include "QuadTree.h"

int main()
{
    // (0.0f, 0.0f) 좌표에서 (200.0f, 200.0f) 크기를 가지는 영역 선언.
    QuadTree tree(Bounds(0.0f, 0.0f, 200.0f, 200.0f));

    // 노드 삽입.
    // 너비와 높이는 모두 1.0f로 통일.
    tree.Insert(new Node(Bounds(50.0f, 50.0f))); // (0: root) -> (1: topLeft) -> (2: bottomRight) -> (3: topLeft) -> (4: topLeft)
    tree.Insert(new Node(Bounds(60.0f, 80.0f)));
    tree.Insert(new Node(Bounds(90.0f, 120.0f)));
    tree.Insert(new Node(Bounds(150.0f, 150.0f)));
    tree.Insert(new Node(Bounds(10.0f, 10.0f)));

    std::cout << "노드를 삽입했습니다.\n";

    Node testNode(Bounds(45.0f, 45.0f, 20.0f, 40.0f));
    std::vector<Node*> intersects = tree.Query(&testNode);
    if (intersects.size() == 0)
    {
        std::cout << "겹치는 노드를 찾지 못했습니다.\n";
    }
    else
    {
        std::cout << "겹치는 노드를 " << intersects.size() << "개 찾았습니다.\n";
    }

	return 0;
}
