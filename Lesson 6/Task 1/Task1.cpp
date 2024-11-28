﻿#include <iostream>

#define MODE 1

#ifndef MODE
	#error необходимо определить MODE
#endif

#if MODE == 1
	int add(int num1, int num2){return num1 + num2;}
#endif

int main()
{
	setlocale(LC_ALL, "Russian");

	#if MODE == 0
		std::cout << "Работаю в режиме тренировки\n";
	#elif MODE == 1
		std::cout << "Работаю в боевом режиме\n";

		int num1{};
		int num2{};

		std::cout << "Введите число 1: ";
		std::cin >> num1;

		std::cout << "Введите число 2: ";
		std::cin >> num2;

		std::cout << "Результат сложения: " << add(num1, num2) << '\n';
	#else
		std::cout << "Неизвестный режим. Завершение работы\n";
	#endif
	
	return 0;
}
