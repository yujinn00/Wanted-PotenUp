#pragma once

// Ŭ���� ����
class IEntity
{
public:
	//Entity();
	//virtual ~Entity(); // ���� �Ҹ��� ����

	//void Move(int xAmount, int yAmount);
	
	// ���� �Լ�
	//virtual const char* GetName() { return "Entity"; }

	// ���� ���� �Լ�
	// ����: �� �Լ��� �ʼ������� �����ϵ��� ������
	virtual const char* GetName() = 0;

	//virtual void Test() {
	//	// ....
	//}

protected:
	int x;
	int y;
};