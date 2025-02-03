#include "GameRoomUser.h"

#include <iostream>

// 방에 입장할 수 있는 최대 유저 수
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
    // 사용자 목록이 비었으면, 사용자 추가 후 방장 이름 설정
    if (users.empty())
    {
        users.emplace_back(userInfo);
        masterUserName = userInfo.userName;
        return true;
    }

    // 최대 허용 인원보다 작으면 사용자 추가
    if (users.size() < maxCount)
    {
        users.emplace_back(userInfo);
        return true;
    }

    cout << "Error: 방이 가득 차서 입장을 하지 못했습니다.\n";

    return false;
}

bool GameRoomUser::DeleteUser(const char* userName)
{
	// 검색 시도
    auto iterator = users.begin();
    for (; iterator != users.end(); ++iterator)
    {
        if (iterator->userName == userName)
        {
            break;
        }
    }

	// 사용자를 찾지 못했을 때
    if (iterator == users.end())
    {
        cout << "Error: 삭제하려는 유저를 찾지 못했습니다.\n";
    }

	// 삭제 처리
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
    // 검색 시도
    auto iterator = users.begin();
    for (; iterator != users.end(); ++iterator)
    {
        // 사용자 정보 찾았으면 변수에 값 할당
        if (iterator->userName == userName)
        {
            outUserInfo = *iterator;
            return true;
        }
    }

    // 실패 처리
	cout << "Error: " << userName << " 유저를 찾지 못했습니다.\n";
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
        cout << "Error: 방이 비어 있습니다.\n";
    }

    return users[users.size() - 1];
}

bool GameRoomUser::BanUser(int orderNum)
{
    if (users.empty())
    {
        cout << "Error: 방이 비어 있어 유저를 내보낼 수 없습니다.\n";
        return false;
    }

    if (users.size() - 1 < (orderNum - 1))
    {
        cout << "Error: 인덱스 계산이 잘못되었습니다.\n";
        return false;
    }

	auto iterator = users.begin() + (orderNum - 1);
	users.erase(iterator);
    if (orderNum == 1 && users.size() > 0)
    {
        masterUserName = users[0].userName;
        cout << "새로운 방장의 이름은 " << masterUserName << " 입니다.\n";
    }

	return true;
}

void GameRoomUser::Clear()
{
    users.clear();
    masterUserName = "";
}
