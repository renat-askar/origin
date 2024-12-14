#include <iostream>

#include "Windows.h"

#include "Greeter.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string name{};
	std::cout << "Введите имя: ";
	std::cin >> name;

	std::cout << Greeter{}.greet(name) << '\n';

	return 0;
}
