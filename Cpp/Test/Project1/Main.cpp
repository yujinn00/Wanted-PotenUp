#include "Bank.h"

#include <iostream>

int main() {
    Bank bank;
    char choice = ' ';

    while (true) {
        std::cout << "====== 은행 계좌 관리 프로그램 ======\n";
        std::cout << "1. 계좌 개설 (CreateAccount)\n";
        std::cout << "2. 입금 (Deposit)\n";
        std::cout << "3. 출금 (Withdraw)\n";
        std::cout << "4. 전체 고객 잔액 조회 (Inquire)\n";
        std::cout << "Q. 종료 (Quit)\n";
        std::cout << "=====================================\n";
        std::cout << "메뉴를 선택하세요: ";

        std::cin >> choice;

        switch (choice)
        {
        case '1':
        {
            system("cls");

            int id;
            char tmpName[100];

            std::cout << "계좌 번호를 입력하세요: ";
            std::cin >> id;
            std::cout << "이름을 입력하세요: ";
            std::cin >> tmpName;

            const char* name = tmpName;
            bank.CreateAccount(id, name, 0);
            break;
        }

        case '2':
        {
            system("cls");

            int id, money;

            std::cout << "계좌 번호를 입력하세요: ";
            std::cin >> id;
            std::cout << "입금하실 금액을 입력하세요: ";
            std::cin >> money;

            bank.Deposit(id, money);
            break;
        }

        case '3':
        {
            system("cls");

            int id, money;

            std::cout << "계좌 번호를 입력하세요: ";
            std::cin >> id;
            std::cout << "출금하실 금액을 입력하세요: ";
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

            std::cout << "프로그램이 종료되었습니다.\n";
            std::cout << "계속하려면 아무 키나 누르십시오 ..\n";
            std::cin.get();

            return 0;

        default:
            system("cls");

            std::cout << "유효하지 않은 값을 입력하셨습니다.\n";
            break;
        }
    }
}
