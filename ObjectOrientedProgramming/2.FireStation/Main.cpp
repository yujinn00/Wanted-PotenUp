#include "Firefighter.h"
#include "FireChief.h"
#include "TraineeFirefighter.h"
#include "FireStation.h"
#include "Administrator.h"

int main()
{
	// 소방서 생성
	FireStation* fireStation = new FireStation();

	// 관리자 생성
	Administrator* taejun = new Administrator("관리자", "태준", "장");

	// 소방차 생성
	Firetruck* truckOne = new Firetruck();

	// 소방관 생성
	Firefighter* ronnie = new Firefighter("로니");
	Firefighter* james = new Firefighter("제임스");

	// 수습 소방관 생성 및 테스트
	Firefighter* bill = new TraineeFirefighter("빌");
	bill->ExtinguishFire();

	// 소방서장 생성
	FireChief* harry = new FireChief("해리", ronnie);
	truckOne->SetDriver(harry);
	harry->Drive(truckOne, Point(200, 300));

	// 출근
	fireStation->ClockIn(ronnie);
	fireStation->ClockIn(james);
	fireStation->ClockIn(bill);
	fireStation->ClockIn(harry);
	fireStation->ClockIn(taejun);

	// 이름 확인
	fireStation->RollCall();

	// 불 끄기 위임
	//harry->TellFirefighterToExtinguishFire(ronnie);
	harry->ExtinguishFire();

	// 다형성
	FirefighterBase* stillHarry = harry;
	stillHarry->ExtinguishFire();

	// 운전자 설정
	truckOne->SetDriver(ronnie);

	// 소방차 이동
	ronnie->Drive(truckOne, Point(10, 5));
	james->Drive(truckOne, Point(20, -3));

	// 운전자 설정
	truckOne->SetDriver(james);

	// 소방차 이동
	james->Drive(truckOne, Point(20, -3));

	// 모메리 해제
	delete truckOne;
	delete ronnie;
	delete james;
	delete bill;
	delete harry;

	delete fireStation;
	delete taejun;

	return 0;
}
