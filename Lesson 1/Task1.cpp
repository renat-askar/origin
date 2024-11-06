#include <iostream>

enum class Month
{
	january = 1,
	february,
	march,
	april,
	may,
	june,
	july,
	august,
	september,
	october,
	november,
	december,
};

int main()
{
	std::setlocale(LC_ALL, "Russian");

	int num{};
	bool zeroIsNotInput{true};
	do
	{
		std::cout << "Введите номер месяца: ";
		std::cin >> num;

		if (!std::cin.eof() && std::cin.peek() != '\n' || !std::cin)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Неправильный номер!\n";
			continue;
		}

		if(num == 0)
			zeroIsNotInput = false;

		if(num >= 1 && num <= 12)
		{
			switch (static_cast<Month>(num))
			{
				case Month::january:	std::cout << "Январь\n";	break;
				case Month::february:	std::cout << "Февраль\n";	break;
				case Month::march:		std::cout << "Март\n";		break;
				case Month::april:		std::cout << "Апрель\n";	break;
				case Month::may:		std::cout << "Май\n";		break;
				case Month::june:		std::cout << "Июнь\n";		break;
				case Month::july:		std::cout << "Июль\n";		break;
				case Month::august:		std::cout << "Август\n";	break;
				case Month::september:	std::cout << "Сентябрь\n";	break;
				case Month::october:	std::cout << "Октябрь\n";	break;
				case Month::november:	std::cout << "Ноябрь\n";	break;
				case Month::december:	std::cout << "Декабрь\n";	break;
			}
		}
		else if(!zeroIsNotInput)
			std::cout << "До свидания\n";
		else
			std::cout << "Неправильный номер!\n";

	} while(zeroIsNotInput);

	return 0;
}
