#include <iostream>

class Figure
{
	int sides_count{};

	virtual bool check() const { return sides_count == 0; }

protected:
	std::string name{};

	Figure(int sides, const std::string &get_name) : sides_count{sides}, name{get_name} {};

public:
	Figure() : name{"Фигура"} {};

	int get_sides_count() const { return sides_count; }
	const std::string &get_name() const { return name; }

	virtual void print_info() const
	{
		std::cout << get_name() << ": \n";
		if (check())
			std::cout << "Правильная\n";
		else
			std::cout << "Неправильная\n";
		std::cout << "Количество сторон: " << sides_count << "\n\n";
	}
};

class Triangle : public Figure
{
	int a{}, b{}, c{};
	int A{}, B{}, C{};

protected:
	Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC, const std::string &name) : a{sideA}, b{sideB}, c{sideC}, A{angleA}, B{angleB}, C{angleC}, Figure{3, name} {}

	virtual bool check() const override { return get_sides_count() == 3 && A + B + C == 180; }

public:
	Triangle() : Figure{3, "Треугольник"} {}

	Triangle(int sideA, int sideB, int sideC, int angleA, int angleB, int angleC) : a{sideA}, b{sideB}, c{sideC}, A{angleA}, B{angleB}, C{angleC}, Figure{3, "Треугольник"} {}

	int get_a() const { return a; }
	int get_b() const { return b; }
	int get_c() const { return c; }
	int get_A() const { return A; }
	int get_B() const { return B; }
	int get_C() const { return C; }

	void print_info() const override
	{
		std::cout << get_name() << ": \n";
		if (check())
			std::cout << "Правильная\n";
		else
			std::cout << "Неправильная\n";
		std::cout << "Количество сторон: " << get_sides_count()
				  << "\nСтороны: a=" << a << " b=" << b << " c=" << c
				  << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n\n";
	}
};

class Quadrangle : public Figure
{
	int a{}, b{}, c{}, d{};
	int A{}, B{}, C{}, D{};

protected:
	Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD, const std::string &name) : a{sideA}, b{sideB}, c{sideC}, d{sideD}, A{angleA}, B{angleB}, C{angleC}, D{angleD}, Figure{4, name} {}

	virtual bool check() const override { return get_sides_count() == 4 && A + B + C + D == 360; }

public:
	Quadrangle() : Figure{4, "Четырёхугольник"} {};

	Quadrangle(int sideA, int sideB, int sideC, int sideD, int angleA, int angleB, int angleC, int angleD) : a{sideA}, b{sideB}, c{sideC}, d{sideD}, A{angleA}, B{angleB}, C{angleC}, D{angleD}, Figure{4, "Четырёхугольник"} {}

	int get_a() const { return a; }
	int get_b() const { return b; }
	int get_c() const { return c; }
	int get_d() const { return d; }
	int get_A() const { return A; }
	int get_B() const { return B; }
	int get_C() const { return C; }
	int get_D() const { return D; }

	void print_info() const override
	{
		std::cout << get_name() << ": \n";
		if (check())
			std::cout << "Правильная\n";
		else
			std::cout << "Неправильная\n";
		std::cout << "Количество сторон: " << get_sides_count()
				  << "\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d
				  << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
	}
};

class RectangularTriangle : public Triangle
{
	bool check() const override
	{
		return Triangle::check() && get_C() == 90;
	}

public:
	RectangularTriangle(int sideA, int sideB, int sideC, int angleA, int angleB) : Triangle{sideA, sideB, sideC, angleA, angleB, 90, "Прямоугольный треугольник"} {}
};

class IsoscelesTriangle : public Triangle
{
	bool check() const override
	{
		return Triangle::check() && get_a() == get_c() && get_A() == get_C();
	}

public:
	IsoscelesTriangle(int sidesAC, int sideB, int anglesAC, int angleB) : Triangle{sidesAC, sideB, sidesAC, anglesAC, angleB, anglesAC, "Равнобедренный треугольник"} {}
};

class EquilateralTriangle : public Triangle
{
	bool check() const override
	{
		return Triangle::check() && get_a() == get_b() && get_a() == get_c() && get_A() == 60 && get_B() == 60 && get_C() == 60;
	}

public:
	EquilateralTriangle(int sides) : Triangle{sides, sides, sides, 60, 60, 60, "Равносторонний треугольник"} {}
};

class Rectangle : public Quadrangle
{
	bool check() const override
	{
		return Quadrangle::check() && get_a() == get_c() && get_b() == get_d() && get_A() == 90 && get_B() == 90 && get_C() == 90 && get_D() == 90;
	}

public:
	Rectangle(int sidesAC, int sidesBD) : Quadrangle{sidesAC, sidesBD, sidesAC, sidesBD, 90, 90, 90, 90, "Прямоугольник"} {}
};

class Square : public Quadrangle
{
	bool check() const override
	{
		return Quadrangle::check() && get_a() == get_b() && get_a() == get_c() && get_a() == get_d() && get_A() == 90 && get_B() == 90 && get_C() == 90 && get_D() == 90;
	}

public:
	Square(int sides) : Quadrangle{sides, sides, sides, sides, 90, 90, 90, 90, "Квадрат"} {}
};

class Parallelogram : public Quadrangle
{
	bool check() const override
	{
		return Quadrangle::check() && get_a() == get_c() && get_b() == get_d() && get_A() == get_C() && get_B() == get_D();
	}

public:
	Parallelogram(int sidesAC, int sidesBD, int anglesAC, int anglesBD) : Quadrangle{sidesAC, sidesBD, sidesAC, sidesBD, anglesAC, anglesBD, anglesAC, anglesBD, "Параллелограмм"} {}
};

class Rhombus : public Quadrangle
{
	bool check() const override
	{
		return Quadrangle::check() && get_a() == get_b() && get_a() == get_c() && get_a() == get_d() && get_A() == get_C() && get_B() == get_D();
	}

public:
	Rhombus(int sides, int anglesAC, int anglesBD) : Quadrangle{sides, sides, sides, sides, anglesAC, anglesBD, anglesAC, anglesBD, "Ромб"} {}
};

int main()
{
	setlocale(LC_ALL, "Russian");

	Figure figure{};

	Triangle triangle{10, 20, 30, 50, 60, 70};

	RectangularTriangle rectangularTriangle{10, 20, 30, 50, 60};
	RectangularTriangle rectangularTriangle1{10, 20, 30, 50, 40};
	IsoscelesTriangle isoscelesTriangle{10, 20, 50, 60};
	EquilateralTriangle equilateralTriangle{30};

	Quadrangle quadrangle{10, 20, 30, 40, 50, 60, 70, 80};

	Rectangle rectangle{10, 20};
	Square square{20};
	Parallelogram parallelogram{20, 30, 30, 40};
	Rhombus rhombus{30, 30, 40};

	figure.print_info();

	triangle.print_info();

	rectangularTriangle.print_info();
	rectangularTriangle1.print_info();
	isoscelesTriangle.print_info();
	equilateralTriangle.print_info();

	quadrangle.print_info();

	rectangle.print_info();
	square.print_info();
	parallelogram.print_info();
	rhombus.print_info();

	return 0;
}
