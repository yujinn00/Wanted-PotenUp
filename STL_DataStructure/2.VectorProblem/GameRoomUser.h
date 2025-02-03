#pragma once

#include <vector>
#include <string>

using namespace std;

// ���� ����
struct UserInfo
{
	UserInfo() = default;
	UserInfo(const string& name, int level, int exp);

	string userName;	// �̸�
	int level = 0;		// ����
	int exp = 0;		// ����ġ
};

// ���� ���� ������ �����ϴ� Ŭ����
// �濡�� �ִ� 6����� ��� �� �� �ִ�.
// �濡 ��� ���� ���� �� ���� ���� ��� �� ����� ������ �ȴ�.
class GameRoomUser
{
public:
	GameRoomUser();
	~GameRoomUser();

	// �濡 ���� �߰�
	bool AddUser(UserInfo& userInfo);

	// �濡�� ���� ����.
	// ���� ������ ������ userName�� ���ο� ������ �̸��� ���� �ؾ� �ȴ�.
	bool DeleteUser(const char* userName);

	// �濡 ������ ������ Ȯ��. ������ true ��ȯ
	bool IsEmpty();

	// �濡 ������ �� á���� Ȯ��. �� á�ٸ� true ��ȯ
	bool IsFull();

	// Ư�� ������ ����
	bool GetUserOfName(const char* userName, UserInfo& userInfo);

	// ������ ���� ���� (�������� ������ ���� => bool ��ȯ ����)
	UserInfo& GetMasterUser();

	// ���� �������� �濡 ��� �� ������ ���� (�������� ������ ���� => bool ��ȯ ����)
	UserInfo& GetUserOfLastOrder();

	// Ư�� ������ ��� �� ������ �i�Ƴ���.
	bool BanUser(int orderNum);

	// ��� ������ �����Ѵ�.
	void Clear();

private:
	vector<UserInfo> users;
	string masterUserName; // ������ �̸�
};
