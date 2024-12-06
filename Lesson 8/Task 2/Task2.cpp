#include <iostream>

class Fraction
{
	private:
		int numerator_;
		int denominator_;

	public:
		Fraction(int numerator, int denominator)
		{
			numerator_ = numerator;
			denominator_ = denominator;
		}

		Fraction operator + (const Fraction& fraction)
		{
			Fraction result{numerator_ * fraction.denominator_ + fraction.numerator_ * denominator_, denominator_ * fraction.denominator_};

			int gcd{result.numerator_ < result.denominator_ ? result.numerator_ : result.denominator_};
			if (gcd > 1)
			{
				while (gcd > 1)
				{
					if (result.numerator_ % gcd == 0 && result.denominator_ % gcd == 0)
						break;
					--gcd;
				}
				result.numerator_ /= gcd;
				result.denominator_ /= gcd;
			}
			return result;
		}

		Fraction operator - (const Fraction& fraction)
		{
			Fraction result{numerator_ * fraction.denominator_ - fraction.numerator_ * denominator_, denominator_ * fraction.denominator_};

			int gcd{result.numerator_ < result.denominator_ ? result.numerator_ : result.denominator_};
			if(gcd > 1)
			{
				while(gcd > 1)
				{
					if (result.numerator_ % gcd == 0 && result.denominator_ % gcd == 0)
						break;
					--gcd;
				}
				result.numerator_ /= gcd;
				result.denominator_ /= gcd;
			}
			return result;
		}

		Fraction operator * (const Fraction& fraction)
		{
			Fraction result{numerator_ * fraction.numerator_, denominator_ * fraction.denominator_};

			int gcd{result.numerator_ < result.denominator_ ? result.numerator_ : result.denominator_};
			if (gcd > 1)
			{
				while (gcd > 1)
				{
					if (result.numerator_ % gcd == 0 && result.denominator_ % gcd == 0)
						break;
					--gcd;
				}
				result.numerator_ /= gcd;
				result.denominator_ /= gcd;
			}
			return result;
		}

		Fraction operator / (const Fraction& fraction)
		{
			Fraction result{numerator_ * fraction.denominator_, denominator_ * fraction.numerator_};

			int gcd{result.numerator_ < result.denominator_ ? result.numerator_ : result.denominator_};
			if (gcd > 1)
			{
				while (gcd > 1)
				{
					if (result.numerator_ % gcd == 0 && result.denominator_ % gcd == 0)
						break;
					--gcd;
				}
				result.numerator_ /= gcd;
				result.denominator_ /= gcd;
			}
			return result;
		}

		Fraction operator - ()
		{
			return numerator_ >= 0 && denominator_ < 0 ? Fraction{numerator_, -denominator_} : Fraction{-numerator_, denominator_};
		}

		Fraction operator ++ (int)
		{
			Fraction temp{*this};
			*this = {numerator_ * 1 + 1 * denominator_, denominator_ * 1};
			return temp;
		}

		Fraction operator ++ ()
		{
			return *this = {numerator_ * 1 + 1 * denominator_, denominator_ * 1};
		}

		Fraction operator -- (int)
		{
			Fraction temp{*this};
			*this = {numerator_ * 1 - 1 * denominator_, denominator_ * 1};
			return temp;
		}

		Fraction operator -- ()
		{
			return *this = {numerator_ * 1 - 1 * denominator_, denominator_ * 1};
		}

		friend std::ostream& operator << (std::ostream& out, const Fraction& fraction);
};

std::ostream& operator << (std::ostream& out, const Fraction& fraction)
{
	return out << fraction.numerator_ << '/' << fraction.denominator_;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int numerator{};
	int denominator{};

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator;
	Fraction fraction1{numerator, denominator};

	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator;
	Fraction fraction2{numerator, denominator};

	std::cout << fraction1 << " + " << fraction2 << " = " << fraction1 + fraction2 << '\n';
	std::cout << fraction1 << " - " << fraction2 << " = " << fraction1 - fraction2 << '\n';
	std::cout << fraction1 << " * " << fraction2 << " = " << fraction1 * fraction2 << '\n';
	std::cout << fraction1 << " / " << fraction2 << " = " << fraction1 / fraction2 << '\n';

	std::cout << "++" << fraction1 << " * " << fraction2 << " = ";
	std::cout << ++fraction1 * fraction2 << '\n';
	std::cout << "Значение дроби 1 = " << fraction1 << '\n';

	std::cout << fraction1 << "-- * " << fraction2 << " = ";
	std::cout << fraction1-- * fraction2 << '\n';
	std::cout << "Значение дроби 1 = " << fraction1 << '\n';
	
	return 0;
}
