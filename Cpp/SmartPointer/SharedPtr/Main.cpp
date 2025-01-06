#include <iostream>

class Resource
{
public:
	Resource()
	{
		std::cout << "�ڿ� ȹ��!\n";
	}

	~Resource()
	{
		std::cout << "�ڿ� ����\n";
	}
};

int main()
{
	std::shared_ptr<Resource> resource1 = std::make_shared<Resource>();
	std::cout << "��� Ƚ��: " << resource1.use_count() << "\n"; // 1

	{
		std::shared_ptr<Resource> resource2 = resource1;
		std::cout << "��� Ƚ��: " << resource1.use_count() << "\n"; // 2
	}
	
	std::cout << "��� Ƚ��: " << resource1.use_count() << "\n"; // 1

	std::shared_ptr<Resource> resource3 = resource1;
	std::cout << "��� Ƚ��: " << resource1.use_count() << "\n"; // 2

	resource3 = nullptr;
	std::cout << "��� Ƚ��: " << resource1.use_count() << "\n"; // 1

	resource1 = nullptr;
	std::cout << "��� Ƚ��: " << resource1.use_count() << "\n"; // 0
}
