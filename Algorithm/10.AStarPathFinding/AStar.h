#pragma once

#include <vector>

// ������ ���� �Լ�.
template<typename T>
void SafeDelete(T* t)
{
	if (t)
	{
		delete t;
		t = nullptr;
	}
}

// A* ��ã�� ��� ó�� Ŭ����.
class Node;
class AStar
{
private:
	// �̵� ���� ����ü.
	struct Direction
	{
		// ����.
		int x = 0;
		int y = 0;

		// ���
		float cost = 0.0f;
	};

public:
	AStar();
	~AStar();

	// ��� �˻� �Լ�.
	std::vector<Node*> FindPath(
		Node* startNode,
		Node* goalNode,
		const std::vector<std::vector<int>>& grid
	);

	// �׸��� ��� �Լ�.
	void DisplayGridWithPath(
		std::vector<std::vector<int>>& grid,
		const std::vector<Node*>& path
	);

private:
	// Ž���� �Ϸ��� �� ���� ��θ� ��ȯ�ϴ� �Լ�.
	// ��ǥ ���κ��� �θ� ��带 �������Ͽ� ��θ� ����.
	std::vector<Node*> ConstructPath(Node* goalNode);

	// hCost ��� �Լ�.
	float CalculateHeuristic(Node* currentNode, Node* goalNode);

	// Ž���Ϸ��� ��ġ�� �׸��� ���� �ȿ� �ִ��� Ȯ���ϴ� �Լ�.
	bool IsInRange(int x, int y, const std::vector<std::vector<int>>& grid);

	// �湮�Ϸ��� ��ġ�� �̹� �湮�� ��ġ���� Ȯ���ϴ� �Լ�.
	// ��� ���� �� �θ� �� ������� �ٲ�� �ϹǷ�, ������ ����� �Ű������� ����.
	bool HasVisited(int x, int y, float gCost);

	// Ž���Ϸ��� ��ġ�� ��ǥ ��ġ���� Ȯ���ϴ� �Լ�.
	bool IsDestination(const Node* node);

private:
	// ���� ����Ʈ.
	std::vector<Node*> openList;

	// ���� ����Ʈ.
	std::vector<Node*> closedList;

	// ���� ���.
	Node* startNode = nullptr;

	// ��ǥ ���.
	Node* goalNode = nullptr;
};
