#include <iostream>

// 타입 정보를 위한 매크로
#define RTTI(name) \
	public:			\
		virtual const char* ClassName() const { return #name; }

class Actor
{
	RTTI(Actor)

public:
	// 가상 함수 추가 (다형성 위함)
	virtual void PrintValue()
	{
		std::cout << "Value: " << a << "\n\n";
	}

protected:
	int a;
};

class Player : public Actor
{
	RTTI(Player)
};

int main()
{
	// 객체 생성
	Actor* actor = new Actor();
	Player* player = new Player();

	// 업 캐스팅
	Actor* actorPointer1 = reinterpret_cast<Actor*>(player); // 굳이 형 변환 안해도 됨
	Actor* actorPointer2 = (Actor*)player; // 굳이 형 변환 안해도 됨
	Actor* actorPointer3 = player;

	// 다운 캐스팅 OK
	Player* playerPointer1 = static_cast<Player*>(actorPointer3);
	Player* playerPointer2 = reinterpret_cast<Player*>(actorPointer3);

	// 다운 캐스팅 Not OK
	Player* playerPointer3 = dynamic_cast<Player*>(actorPointer3); // 에러 발생 (단, 기본 클래스에 "가상 함수" 만들면 에러 발생 X)
	//Player* playerPointer4 = static_cast<Player*>(actor); // 에러는 안 나지만, 형 변환 실패

	// 예외 처리
	// dynamic_cast: 안전 ..?
	if (playerPointer3)
	{
		// 함수 호출
		playerPointer3->PrintValue();
	}
	else
	{
		std::cout << "형 변환 실패\n\n";
	}

	//////////////////////////////////////////////////////////////

	// typeid
	const type_info& info = typeid(actorPointer3);
	std::cout << "타입 이름: " << info.name() << "\n\n";

	//////////////////////////////////////////////////////////////

	std::cout << "Actor 타입: " << actor->ClassName() << "\n";
	std::cout << "Player 타입: " << player->ClassName() << "\n";
	std::cout << "Player 타입: " << actorPointer3->ClassName() << "\n\n";


	// 타입 비교
	if (strcmp(actor->ClassName(), player->ClassName()) == 0)
	{
		std::cout << "타입 동일\n\n";
	}
	else
	{
		std::cout << "타입 다름\n\n";
	}
}
