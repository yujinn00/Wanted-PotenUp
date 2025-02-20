#include "AStar.h"
#include "Node.h"

AStar::AStar()
{
}

AStar::~AStar()
{
	// �޸� ����.
	for (Node* node : openList)
	{
		SafeDelete(node);
	}

	openList.clear();

	for (Node* node : closedList)
	{
		SafeDelete(node);
	}

	closedList.clear();
}

std::vector<Node*> AStar::FindPath(Node* startNode, Node* goalNode, const std::vector<std::vector<int>>& grid)
{
	// ���� ����/��ǥ ���� ����.
	this->startNode = startNode;
	this->goalNode = goalNode;

	// ���� ��带 ���� ����Ʈ�� �߰�.
	openList.emplace_back(startNode);

	// �����¿� �� �밢�� �̵� ����� ��� ���.
	std::vector<Direction> directions =
	{
		// �ϻ���� �̵�.
		// { x, y, ��� }.
		{ 0, 1, 1.0f }, { 0, -1, 1.0f }, { 1, 0, 1.0f }, { -1, 0, 1.0f },

		// �밢�� �̵�.
		// ���� �ϴ�, ���� ���, ���� �ϴ�, ���� ���.
		// 1.414f = sqrt(2).
		{ 1, 1, 1.414f }, { 1, -1, 1.414f }, { -1, 1, 1.414f }, { -1, -1, 1.414f }
	};

	// �̿� ��� Ž�� (���� ����Ʈ�� ��� ���� ������ �ݺ�).
	while (!openList.empty())
	{
		// ���� ���� ����Ʈ���� fCost�� ���� ���� ��� �˻�.
		// ����ȭ ���� (�켱���� ť, ��).
		// ��, �츮�� ����ȭ���� ���� ����.
		Node* lowestNode = openList[0];
		for (Node* node : openList)
		{
			if (node->fCost < lowestNode->fCost)
			{
				lowestNode = node;
			}
		}

		// fCost�� ���� ���� ��带 ���� ���� ����.
		Node* currentNode = lowestNode;

		// ���� ��尡 ��ǥ ������� Ȯ�� �� ������ ����.
		if (IsDestination(currentNode))
		{
			// ��ǥ �������κ��� �������Ͽ� ��θ� ���� �� ��ȯ.
			return ConstructPath(currentNode);
		}

		// �湮 ó���� ���� ���� ��带 ���� ����Ʈ���� ����.
		for (int ix = 0; ix < (int)openList.size(); ++ix)
		{
			// �����ͳ����� �ּ� �� ���̹Ƿ� Ʋ�� ���� �ƴ����� ��Ȯ���ϹǷ�,
			// �츰 ������ �����ε��� �ؼ� ��ġ ������� ����.
			// �ƴϸ� �׳� *openList[ix]->positon���� �ٷ� ���ص� ��.
			if (*openList[ix] == *currentNode)
			{
				openList.erase(openList.begin() + ix);
				break;
			}
		}

		// �湮 ó���� ���� ���� ��带 ���� ����Ʈ�� �߰�.
		// �̹� �߰��� ���� ����.
		bool isNodeInList = false;
		for (Node* node : closedList)
		{
			// �̰͵� ������ �����ε��� ���� ��ġ ������� ��.
			if (*node == *currentNode)
			{
				isNodeInList = true;
				break;
			}
		}

		// �̹� ������ ����.
		if (isNodeInList)
		{
			continue;
		}

		// ������ ���� ����Ʈ�� �߰�.
		closedList.emplace_back(currentNode);

		// �̿� ��� �湮 (�ϻ���� ���ʷ� �湮).
		for (const Direction& direction : directions)
		{
			// ������ �̵��� ��ġ ����.
			int newX = currentNode->position.x + direction.x;
			int newY = currentNode->position.y + direction.y;

			// �׸��� ����� ����.
			if (!IsInRange(newX, newY, grid))
			{
				continue;
			}

			// �̵��� ��ġ�� ��ֹ��̸� ����.
			// Y����, �� ���� X.
			if (grid[newY][newX] == 1)
			{
				continue;
			}

			// �̹� �湮�� ����̸� ����.
			if (HasVisited(newX, newY, currentNode->gCost + direction.cost))
			{
				continue;
			}

			// �湮�� ��� ����.
			// �湮�� ����� gCost, hCost, fCost ���.
			Node* neighborNode = new Node(newX, newY, currentNode);
			neighborNode->gCost = currentNode->gCost + direction.cost;
			neighborNode->hCost = CalculateHeuristic(neighborNode, goalNode);
			neighborNode->fCost = neighborNode->gCost + neighborNode->hCost;

			// �̿� ��尡 �̹� ���� ����Ʈ�� �ִ��� Ȯ��.
			Node* openListNode = nullptr;
			for (Node* node : openList)
			{
				// �̰͵� ������ �����ε��� ���� ��ġ ������� ��.
				if (*node == *neighborNode)
				{
					openListNode = node;
					break;
				}
			}

			// �̿� ��尡 ���� ����Ʈ�� ���ٸ�, �湮�� ���� ���� ����Ʈ�� �߰�.
			// �̿� ��尡 ���� ����Ʈ�� �ִٸ�, gCost�� fCost�� ���� �� �����ϸ� ���� ����Ʈ�� �߰�.
			if (openListNode == nullptr
				|| neighborNode->gCost < openListNode->gCost
				|| neighborNode->fCost < openListNode->fCost)
			{
				openList.emplace_back(neighborNode);
			}
			else
			{
				// ����Ʈ �߰� ����� �ƴ϶��, �޸� ����.
				SafeDelete(neighborNode);
			}
		}
	}

	// Ž�� ����
	return std::vector<Node*>();
}

std::vector<Node*> AStar::ConstructPath(Node* goalNode)
{
	// ��ǥ ���κ��� �θ� ��带 ���� �������ϸ鼭 ��� ����.
	std::vector<Node*> path;
	Node* currentNode = goalNode;
	while (currentNode != nullptr)
	{
		path.emplace_back(currentNode);
		currentNode = currentNode->parent;
	}

	// ���� �������� ��ǥ �������� ���ϵ��� �迭 ������.
	std::reverse(path.begin(), path.end());
	return path;
}

float AStar::CalculateHeuristic(Node* currentNode, Node* goalNode)
{
	// ���� ��忡�� ��ǥ �������� �Ÿ��� ���� ���.
	Position diff = *currentNode - *goalNode;

	// T pow(T base, T n) => base�� �Ǵ� ������ n ������ ���ϴ� �Լ�.
	return std::sqrtf(diff.x * diff.x + diff.y * diff.y);
}

bool AStar::IsInRange(int x, int y, const std::vector<std::vector<int>>& grid)
{
	// ������ ����� false ��ȯ.
	if (x < 0 || x >= grid[0].size() || y < 0 || y >= grid.size())
	{
		return false;
	}

	// ������ ����� ������ true ��ȯ.
	return true;
}

bool AStar::HasVisited(int x, int y, float gCost)
{
	// ����/���� ����Ʈ�� �̹� �ش� ��ġ�� ������ �湮�� ������ �Ǵ�.
	for (int ix = 0; ix < (int)openList.size(); ++ix)
	{
		Node* node = openList[ix];
		if ((node->position.x == x && node->position.y == y))
		{
			// ��ġ�� ������, ����� �� ũ�� �湮�� ������ �����Ƿ�, �湮�ߴٰ� �Ǵ�.
			if (gCost >= node->gCost)
			{
				return true;
			}
			// ��ġ�� ������, ����� �� ������ �湮�� �ʿ䰡 �����Ƿ�, ������ ��� ����.
			else
			{
				openList.erase(openList.begin() + ix);
				SafeDelete(node);
			}
		}
	}

	for (int ix = 0; ix < (int)closedList.size(); ++ix)
	{
		Node* node = closedList[ix];
		if ((node->position.x == x && node->position.y == y))
		{
			// ��ġ�� ������, ����� �� ũ�� �湮�� ������ �����Ƿ�, �湮�ߴٰ� �Ǵ�.
			if (gCost >= node->gCost)
			{
				return true;
			}

			// ��ġ�� ������, ����� �� ������ �湮�� �ʿ䰡 �����Ƿ�, ������ ��� ����.
			else
			{
				closedList.erase(closedList.begin() + ix);
				SafeDelete(node);
			}
		}
	}

	// ����Ʈ�� ������ �湮���� ���� ������ �Ǵ�.
	return false;
}

bool AStar::IsDestination(const Node* node)
{
	// ����� ��ġ�� ���� ������ ��.
	return *node == *goalNode;
}

void AStar::DisplayGridWithPath(std::vector<std::vector<int>>& grid, const std::vector<Node*>& path)
{
	// ��ο� �ִ� ��ġ�� 2�� ǥ��.
	for (const Node* node : path)
	{
		grid[node->position.y][node->position.x] = 2;
	}

	// �� ���.
	// Y����, �� ���� X.
	for (int y = 0; y < (int)grid.size(); ++y)
	{
		for (int x = 0; x < (int)grid[0].size(); ++x)
		{
			// ��ֹ�.
			if (grid[y][x] == 1)
			{
				std::cout << "1 ";
			}

			// ���.
			else if (grid[y][x] == 2)
			{
				std::cout << "+ ";
			}

			// ��.
			else if (grid[y][x] == 0)
			{
				std::cout << "0 ";
			}
		}

		std::cout << "\n";
	}
}
