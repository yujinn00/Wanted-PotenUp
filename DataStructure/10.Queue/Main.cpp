#include <iostream>
#include "Queue.h"

int main()
{
	Queue queue;
	for (int i = 0; i < 10; ++i)
	{
		queue.Enqueue(i + 10);
	}

	// 큐 출력
	queue.Print();

	std::cout << "=== 큐 요소 제거 ===\n";
	int value = 0;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);

	// 큐 출력
	queue.Print();
}
