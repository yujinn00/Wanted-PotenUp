#include "GameRoomUser.h"

#include <iostream>

// �濡 ������ �� �ִ� �ִ� ���� ��
static const int maxCount = 6;

UserInfo::UserInfo(const string& name, int level, int exp)
    : userName(name), level(level), exp(exp)
{
}

GameRoomUser::GameRoomUser()
{
}

GameRoomUser::~GameRoomUser()
{
}

bool GameRoomUser::AddUser(UserInfo& userInfo)
{
    // ����� ����� �������, ����� �߰� �� ���� �̸� ����
    if (users.empty())
    {
        users.emplace_back(userInfo);
        masterUserName = userInfo.userName;
        return true;
    }

    // �ִ� ��� �ο����� ������ ����� �߰�
    if (users.size() < maxCount)
    {
        users.emplace_back(userInfo);
        return true;
    }

    cout << "Error: ���� ���� ���� ������ ���� ���߽��ϴ�.\n";

    return false;
}

bool GameRoomUser::DeleteUser(const char* userName)
{
	// �˻� �õ�
    auto iterator = users.begin();
    for (; iterator != users.end(); ++iterator)
    {
        if (iterator->userName == userName)
        {
            break;
        }
    }

	// ����ڸ� ã�� ������ ��
    if (iterator == users.end())
    {
        cout << "Error: �����Ϸ��� ������ ã�� ���߽��ϴ�.\n";
    }

	// ���� ó��
    if (iterator == users.begin() && users.size() > 1)
    {
        masterUserName = users[1].userName;
    }

    users.erase(iterator);
	return true;
}

bool GameRoomUser::IsEmpty()
{
    return users.empty();
}

bool GameRoomUser::IsFull()
{
    return users.size() == maxCount;
}

bool GameRoomUser::GetUserOfName(const char* userName, UserInfo& outUserInfo)
{
    // �˻� �õ�
    auto iterator = users.begin();
    for (; iterator != users.end(); ++iterator)
    {
        // ����� ���� ã������ ������ �� �Ҵ�
        if (iterator->userName == userName)
        {
            outUserInfo = *iterator;
            return true;
        }
    }

    // ���� ó��
	cout << "Error: " << userName << " ������ ã�� ���߽��ϴ�.\n";
	return false;
}

UserInfo& GameRoomUser::GetMasterUser()
{
    return users[0];
}

UserInfo& GameRoomUser::GetUserOfLastOrder()
{
    if (users.empty())
    {
        cout << "Error: ���� ��� �ֽ��ϴ�.\n";
    }

    return users[users.size() - 1];
}

bool GameRoomUser::BanUser(int orderNum)
{
    if (users.empty())
    {
        cout << "Error: ���� ��� �־� ������ ������ �� �����ϴ�.\n";
        return false;
    }

    if (users.size() - 1 < (orderNum - 1))
    {
        cout << "Error: �ε��� ����� �߸��Ǿ����ϴ�.\n";
        return false;
    }

	auto iterator = users.begin() + (orderNum - 1);
	users.erase(iterator);
    if (orderNum == 1 && users.size() > 0)
    {
        masterUserName = users[0].userName;
        cout << "���ο� ������ �̸��� " << masterUserName << " �Դϴ�.\n";
    }

	return true;
}

void GameRoomUser::Clear()
{
    users.clear();
    masterUserName = "";
}
