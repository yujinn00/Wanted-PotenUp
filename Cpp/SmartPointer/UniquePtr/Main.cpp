#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

class Resource
{
public:
	Resource()
	{
		std::cout << "������ ȣ��\n";
	}

	~Resource()
	{
		std::cout << "�Ҹ��� ȣ��\n";
	}

	void Use()
	{
		std::cout << "�ڿ� ���\n";
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(157);

	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	//Resource* resource = new Resource();
	
	resource->Use();

	//std::unique_ptr<Resource> resource2 = resource; // ����ũ �����Ͱ� �����߱� ������, resource�� ������ �Լ���� ��
	std::unique_ptr<Resource> resource2 = std::move(resource); // ��, move �Լ��� ����ϸ� �������� �����ǹǷ� ����� ������
	
	//resource->Use(); // �ʷϻ� warning ����: �ٷ� �� �ڵ忡�� �������� ���������Ƿ�, ���� ����ϸ� �ȵ� => �ٵ� ������ ������, �� ���ڱ� �ȵ� ���� ����
	resource2->Use();

	// ���� ������ get()
	Resource* rawPointer = resource2.get();
	rawPointer->Use();

	//delete rawPointer; // _free_dbg(block, _UNKNOWN_BLOCK); => �̷��� �ߴ��� ��� ������ �߻��ϸ�, �� delete �ߺ� ȣ���̶� �ǹ�
}
