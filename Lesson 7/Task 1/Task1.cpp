#include <iostream>
#include <string>

#include "Windows.h"

int function(std::string str, int forbidden_length)
{
	if(str.length() == forbidden_length)
	{
		throw "Вы ввели слово запретной длины! До свидания";
	}
	return str.length();
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int length{};
	std::cout << "Введите запретную длину: ";
	std::cin >> length;

	std::string word{};
	while(true)
	{
		std::cout << "Введите слово: ";
		std::cin >> word;
		try
		{
			std::cout << "Длина слова " << word << " равна " << function(word, length) << '\n';
		}
		catch (const char* bad_length)
		{
			std::cout << bad_length << '\n';
			break;
		}
	}

	return EXIT_SUCCESS;
}
