#include "Firefighter.h"
#include "FireChief.h"
#include "TraineeFirefighter.h"
#include "FireStation.h"
#include "Administrator.h"

int main()
{
	// �ҹ漭 ����
	FireStation* fireStation = new FireStation();

	// ������ ����
	Administrator* taejun = new Administrator("������", "����", "��");

	// �ҹ��� ����
	Firetruck* truckOne = new Firetruck();

	// �ҹ�� ����
	Firefighter* ronnie = new Firefighter("�δ�");
	Firefighter* james = new Firefighter("���ӽ�");

	// ���� �ҹ�� ���� �� �׽�Ʈ
	Firefighter* bill = new TraineeFirefighter("��");
	bill->ExtinguishFire();

	// �ҹ漭�� ����
	FireChief* harry = new FireChief("�ظ�", ronnie);
	truckOne->SetDriver(harry);
	harry->Drive(truckOne, Point(200, 300));

	// ���
	fireStation->ClockIn(ronnie);
	fireStation->ClockIn(james);
	fireStation->ClockIn(bill);
	fireStation->ClockIn(harry);
	fireStation->ClockIn(taejun);

	// �̸� Ȯ��
	fireStation->RollCall();

	// �� ���� ����
	//harry->TellFirefighterToExtinguishFire(ronnie);
	harry->ExtinguishFire();

	// ������
	FirefighterBase* stillHarry = harry;
	stillHarry->ExtinguishFire();

	// ������ ����
	truckOne->SetDriver(ronnie);

	// �ҹ��� �̵�
	ronnie->Drive(truckOne, Point(10, 5));
	james->Drive(truckOne, Point(20, -3));

	// ������ ����
	truckOne->SetDriver(james);

	// �ҹ��� �̵�
	james->Drive(truckOne, Point(20, -3));

	// ��޸� ����
	delete truckOne;
	delete ronnie;
	delete james;
	delete bill;
	delete harry;

	delete fireStation;
	delete taejun;

	return 0;
}
