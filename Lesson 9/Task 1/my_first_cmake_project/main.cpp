#include "Windows.h"

#include <iostream>
#include <string>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::string name{};

	std::cout << "Введите имя: ";
	std::cin >> name;
	
	std::cout << "Здраствуйте, " << name << '\n';
	
	return 0;
}
