#include <iostream>
#include <string>

struct Address
{
	std::string cityName{};
	std::string streetName{};
	int houseNumber{};
	int apartmentNumber{};
	int index{};
};

void printAddress(Address& address)
{
	std::cout << "Город: " << address.cityName << '\n'
	<< "Улица: " << address.streetName << '\n'
	<< "Номер дома: " << address.houseNumber << '\n'
	<< "Номер квартиры: " << address.apartmentNumber << '\n'
	<< "Индекс: " << address.index << '\n';
}

int main()
{
	setlocale(LC_ALL, "Russian");

	Address address1{"Москва", "Арбат", 12, 8, 123456};
	Address address2{"Ижевск", "Пушкина", 59, 143, 953769};

	printAddress(address1);

	std::cout << '\n';

	printAddress(address2);

	return 0;
}
