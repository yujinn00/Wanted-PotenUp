#include "Firefighter.h"
#include "FireChief.h"

int main()
{
	// 소방차 생성
	Firetruck* truckOne = new Firetruck();

	// 소방관 생성
	Firefighter* yujin = new Firefighter("유진");
	Firefighter* taehee = new Firefighter("태희");

	// 소방서장 생성
	FireChief* taemin = new FireChief("태민");
	truckOne->SetDriver(taemin);
	taemin->Drive(truckOne, Point(200, 300));

	// 불 끄기 위임
	taemin->TellFirefighterToExtinguishFire(yujin);

	// 운전자 설정
	truckOne->SetDriver(yujin);

	// 소방차 이동
	yujin->Drive(truckOne, Point(10, 5));

	// 운전자 설정
	truckOne->SetDriver(taehee);

	// 소방차 이동
	taehee->Drive(truckOne, Point(20, -3));

	return 0;
}
