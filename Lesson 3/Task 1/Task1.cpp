#include <iostream>
#include <fstream>
#include <string>

class Address
{
	std::string city{};
	std::string street{};
	int house{};
	int apartment{};

public:
	Address() = default;

	Address(const std::string& setCity, const std::string& setStreet, int setHouse, int setApartment) :
		city{setCity}, street{setStreet}, house{setHouse}, apartment{setApartment}{}

	std::string& getCity(){return city;}
	std::string& getStreet(){return street;}
	int& getHouse(){return house;}
	int& getApartment(){return apartment;}

	std::string get_output_address()
	{
		return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
	}
};

int main()
{
	ptrdiff_t n_Addresses{};
	std::ifstream inputFile{ "in.txt" };
	inputFile >> n_Addresses;

	Address* addresses{new Address[n_Addresses]{}};

	for(ptrdiff_t addr{}; addr < n_Addresses; ++addr)
	{
		inputFile >> addresses[addr].getCity();
		inputFile >> addresses[addr].getStreet();
		inputFile >> addresses[addr].getHouse();
		inputFile >> addresses[addr].getApartment();
	}
	inputFile.close();

	std::ofstream outputFile{ "out.txt" };
	outputFile << n_Addresses << '\n';

	for(ptrdiff_t addr{n_Addresses - 1}; addr > -1; --addr)
	{
		outputFile << addresses[addr].get_output_address() << '\n';
	}
	outputFile.close();

	delete[] addresses;

	return EXIT_SUCCESS;
}
