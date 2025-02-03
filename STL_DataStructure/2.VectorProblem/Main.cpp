#include "GameRoomUser.h"

#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

ostream& operator<<(ostream& os, UserInfo& userInfo)
{
	return os << "UserName: " << userInfo.userName
		<< ", Level: " << userInfo.level << ", Exp: " << userInfo.exp << endl;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	// �� ����
	GameRoomUser gameRoom;

	// ���� �߰�
	UserInfo user1("RonnieJ", 1, 30);
	gameRoom.AddUser(user1);

	UserInfo user2("Hamtol2", 10, 670);
	gameRoom.AddUser(user2);

	UserInfo user3("TaeJun", 5, 250);
	gameRoom.AddUser(user3);

	UserInfo user4("Oops", 32, 1250);
	gameRoom.AddUser(user4);

	UserInfo user5("Gamer", 40, 250);
	gameRoom.AddUser(user5);

	UserInfo user6("GameDev", 80, 3425);
	gameRoom.AddUser(user6);

	UserInfo user7("STL", 23, 890);
	gameRoom.AddUser(user7);

	// ���� Ȯ��
	UserInfo roomMaster = gameRoom.GetMasterUser();
	if (roomMaster.userName != "")
	{
		cout << "������ " << roomMaster.userName << " �Դϴ�.\n";
	}

	// ���� ��
	gameRoom.BanUser(1);

	// 3�� ��
	gameRoom.BanUser(3);

	// TaeJun�� ���� Ȯ��
	UserInfo outValue;
	if (gameRoom.GetUserOfName("TaeJun", outValue))
	{
		cout << "[TaeJun�� ����] " << outValue;
	}

	// �ٸ� ������� ���� Ȯ��
	if(gameRoom.GetUserOfName("Test", outValue))
	{
		cout << "[Test�� ����] " << outValue;
	}

	// �������� �濡 ���� ���� ����
	cout << "[���� �������� ���� ���� ����] " << gameRoom.GetUserOfLastOrder();

	// ��� ���� ����
	gameRoom.Clear();

	// ��� ���� ���� �� ������� Ȯ��
	cout << (gameRoom.IsEmpty() == true ? "���� ������ϴ�.\n" : "���� ������� �ʽ��ϴ�\n");

	cin.get();
}
