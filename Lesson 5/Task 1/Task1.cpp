#include <iostream>

#include "calculator.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	int num1{};
	int num2{};
	int select{};

	std::cout << "Введите первое число: ";
	std::cin >> num1;

	std::cout << "Введите второе число: ";
	std::cin >> num2;

	std::cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	std::cin >> select;

	switch (select)
	{
		case 1:
		{
			std::cout << num1 << " плюс " << num2 << " = " << add(num1, num2) << '\n'; break;
		}
		case 2:
		{
			std::cout << num1 << " минус " << num2 << " = " << sub(num1, num2) << '\n'; break;
		}
		case 3:
		{
			std::cout << num1 << " умножить на " << num2 << " = " << mul(num1, num2) << '\n'; break;
		}
		case 4:
		{
			std::cout << num1 << " делить на " << num2 << " = " << divi(num1, num2) << '\n'; break;
		}
		case 5:
		{
			std::cout << num1 << " в степени " << num2 << " = " << pow(num1, num2) << '\n'; break;
		}
	}

	return 0;
}
