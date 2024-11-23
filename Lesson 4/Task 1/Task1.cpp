#include <iostream>

class Figure
{
	int sides_count{};
	std::string name{};

protected:
	Figure(int sides, const std::string &p_name) : sides_count{sides}, name{p_name} {};

public:
	Figure() : name{"Фигура"} {};

	int get_sides_count() const { return sides_count; }
	const std::string &get_name() const { return name; }
};

class Triangle : public Figure
{
public:
	Triangle() : Figure{3, "Треугольник"} {}
};

class Quadrangle : public Figure
{
public:
	Quadrangle() : Figure{4, "Четырёхугольник"} {};
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Figure figure{};
	Triangle triangle{};
	Quadrangle quadrangle{};

	std::cout << "Количество сторон: \n"
			  << figure.get_name() << ": " << figure.get_sides_count() << '\n'
			  << triangle.get_name() << ": " << triangle.get_sides_count() << '\n'
			  << quadrangle.get_name() << ": " << quadrangle.get_sides_count() << '\n';

	return 0;
}
