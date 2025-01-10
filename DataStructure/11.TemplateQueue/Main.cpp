#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> queue;

	queue.Enqueue(10);
	queue.Enqueue(20);
	queue.Enqueue(30);
	queue.Enqueue(40);
	queue.Enqueue(50);
	queue.Enqueue(60);

	std::cout << "===== ������ �߰� �� ��� =====\n";
	queue.Print();

	int outValue = 0;

	if (queue.Dequeue(outValue))
	{
		std::cout << "ť���� ��µ� ��: " << outValue << "\n";
	}

	if (queue.Dequeue(outValue))
	{
		std::cout << "ť���� ��µ� ��: " << outValue << "\n";
	}

	if (queue.Dequeue(outValue))
	{
		std::cout << "ť���� ��µ� ��: " << outValue << "\n";
	}

	std::cout << "===== ������ ���� �� ��� =====\n";
	queue.Print();
}
