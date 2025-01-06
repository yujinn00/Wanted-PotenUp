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
		std::cout << "생성자 호출\n";
	}

	~Resource()
	{
		std::cout << "소멸자 호출\n";
	}

	void Use()
	{
		std::cout << "자원 사용\n";
	}
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(157);

	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	//Resource* resource = new Resource();
	
	resource->Use();

	//std::unique_ptr<Resource> resource2 = resource; // 유니크 포인터가 삭제했기 때문에, resource는 삭제된 함수라고 뜸
	std::unique_ptr<Resource> resource2 = std::move(resource); // 단, move 함수를 사용하면 소유권이 이전되므로 사용이 가능함
	
	//resource->Use(); // 초록색 warning 이유: 바로 위 코드에서 소유권을 이전했으므로, 원래 사용하면 안됨 => 근데 지금은 되지만, 또 갑자기 안될 수도 있음
	resource2->Use();

	// 원시 포인터 get()
	Resource* rawPointer = resource2.get();
	rawPointer->Use();

	//delete rawPointer; // _free_dbg(block, _UNKNOWN_BLOCK); => 이러한 중단점 명령 실행이 발생하면, 곧 delete 중복 호출이란 의미
}
