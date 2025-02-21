#include <iostream>

#include "QuadTree.h"

int main()
{
    // (0.0f, 0.0f) ��ǥ���� (200.0f, 200.0f) ũ�⸦ ������ ���� ����.
    QuadTree tree(Bounds(0.0f, 0.0f, 200.0f, 200.0f));

    // ��� ����.
    // �ʺ�� ���̴� ��� 1.0f�� ����.
    tree.Insert(new Node(Bounds(50.0f, 50.0f))); // (0: root) -> (1: topLeft) -> (2: bottomRight) -> (3: topLeft) -> (4: topLeft)
    tree.Insert(new Node(Bounds(60.0f, 80.0f)));
    tree.Insert(new Node(Bounds(90.0f, 120.0f)));
    tree.Insert(new Node(Bounds(150.0f, 150.0f)));
    tree.Insert(new Node(Bounds(10.0f, 10.0f)));

    std::cout << "��带 �����߽��ϴ�.\n";

    Node testNode(Bounds(45.0f, 45.0f, 20.0f, 40.0f));
    std::vector<Node*> intersects = tree.Query(&testNode);
    if (intersects.size() == 0)
    {
        std::cout << "��ġ�� ��带 ã�� ���߽��ϴ�.\n";
    }
    else
    {
        std::cout << "��ġ�� ��带 " << intersects.size() << "�� ã�ҽ��ϴ�.\n";
    }

	return 0;
}
