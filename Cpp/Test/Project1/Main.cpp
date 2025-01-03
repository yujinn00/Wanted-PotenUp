#include "Bank.h"

#include <iostream>

int main() {
    Bank bank;
    char choice = ' ';

    while (true) {
        std::cout << "====== ���� ���� ���� ���α׷� ======\n";
        std::cout << "1. ���� ���� (CreateAccount)\n";
        std::cout << "2. �Ա� (Deposit)\n";
        std::cout << "3. ��� (Withdraw)\n";
        std::cout << "4. ��ü �� �ܾ� ��ȸ (Inquire)\n";
        std::cout << "Q. ���� (Quit)\n";
        std::cout << "=====================================\n";
        std::cout << "�޴��� �����ϼ���: ";

        std::cin >> choice;

        switch (choice)
        {
        case '1':
        {
            system("cls");

            int id;
            char tmpName[100];

            std::cout << "���� ��ȣ�� �Է��ϼ���: ";
            std::cin >> id;
            std::cout << "�̸��� �Է��ϼ���: ";
            std::cin >> tmpName;

            const char* name = tmpName;
            bank.CreateAccount(id, name, 0);
            break;
        }

        case '2':
        {
            system("cls");

            int id, money;

            std::cout << "���� ��ȣ�� �Է��ϼ���: ";
            std::cin >> id;
            std::cout << "�Ա��Ͻ� �ݾ��� �Է��ϼ���: ";
            std::cin >> money;

            bank.Deposit(id, money);
            break;
        }

        case '3':
        {
            system("cls");

            int id, money;

            std::cout << "���� ��ȣ�� �Է��ϼ���: ";
            std::cin >> id;
            std::cout << "����Ͻ� �ݾ��� �Է��ϼ���: ";
            std::cin >> money;

            bank.Withdraw(id, money);
            break;
        }

        case '4':
            system("cls");

            bank.Inquire();
            break;

        case 'Q':
            system("cls");

            std::cout << "���α׷��� ����Ǿ����ϴ�.\n";
            std::cout << "����Ϸ��� �ƹ� Ű�� �����ʽÿ� ..\n";
            std::cin.get();

            return 0;

        default:
            system("cls");

            std::cout << "��ȿ���� ���� ���� �Է��ϼ̽��ϴ�.\n";
            break;
        }
    }
}
