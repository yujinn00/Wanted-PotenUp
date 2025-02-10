#include "Firefighter.h"
#include "FireChief.h"

int main()
{
	// �ҹ��� ����
	Firetruck* truckOne = new Firetruck();

	// �ҹ�� ����
	Firefighter* yujin = new Firefighter("����");
	Firefighter* taehee = new Firefighter("����");

	// �ҹ漭�� ����
	FireChief* taemin = new FireChief("�¹�");
	truckOne->SetDriver(taemin);
	taemin->Drive(truckOne, Point(200, 300));

	// �� ���� ����
	taemin->TellFirefighterToExtinguishFire(yujin);

	// ������ ����
	truckOne->SetDriver(yujin);

	// �ҹ��� �̵�
	yujin->Drive(truckOne, Point(10, 5));

	// ������ ����
	truckOne->SetDriver(taehee);

	// �ҹ��� �̵�
	taehee->Drive(truckOne, Point(20, -3));

	return 0;
}
