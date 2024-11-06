#include "Windows.h"

#include <iostream>
#include <string>

struct BankAccount
{
	int number{};
	std::string name{};
	double balance{};
};

void changeAccountBalance(BankAccount& bankAccount)
{
	std::cout << "Введите номер счёта: ";
	std::cin >> bankAccount.number;

	std::cout << "Введите имя владельца: ";
	std::cin >> bankAccount.name;

	std::cout << "Введите новый баланс: ";
	std::cin >> bankAccount.balance;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BankAccount owner{};

	changeAccountBalance(owner);

	std::cout << "Ваш счёт: " << owner.name << ", " << owner.number << ", " << owner.balance << '\n';

	return 0;
}
