#include <iostream>
#include <limits>

class Calculator
{
    double num1{};
    double num2{};

    public:
        double add()
        {
            return num1 + num2;
        }
        double multiply()
        {
            return num1 * num2;
        }
        double subtract_1_2()
        {
            return num1 - num2;
        }
        double subtract_2_1()
        {
            return num2 - num1;
        }
        double divide_1_2()
        {
            return num1 / num2;
        }
        double divide_2_1()
        {
            return num2 / num1;
        }
        bool set_num1(double num1)
        {
            if(num1)
            {
                this->num1 = num1;
                return true;
            }
            return false;
        }
        bool set_num2(double num2)
        {
            if(num2)
            {
                this->num2 = num2;
                return true;
            }
            return false;
        }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Calculator calculator{};
    double num1{};
    double num2{};
    bool num1IsNotZero{};
    bool num2IsNotZero{};
    while(true)
    {
        while(!num1IsNotZero)
        {
            while(std::cout << "Введите num1: " && !(std::cin >> num1) || !std::cin.eof() && std::cin.peek() != '\n')
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Неверный ввод!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            num1IsNotZero = calculator.set_num1(num1);
            if(!num1IsNotZero)
            {
                std::cout << "Неверный ввод!\n";
                continue;
            }
        }

        while(!num2IsNotZero)
        {
            while(std::cout << "Введите num2: " && !(std::cin >> num2) || !std::cin.eof() && std::cin.peek() != '\n')
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Неверный ввод!\n";
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            num2IsNotZero = calculator.set_num2(num2);
            if(!num2IsNotZero)
            {
                std::cout << "Неверный ввод!\n";
                continue;
            }
        }

        std::cout << "num1 + num2 = " << calculator.add() << '\n';
        std::cout << "num1 - num2 = " << calculator.subtract_1_2() << '\n';
        std::cout << "num2 - num1 = " << calculator.subtract_2_1() << '\n';
        std::cout << "num1 * num2 = " << calculator.multiply() << '\n';
        std::cout << "num1 / num2 = " << calculator.divide_1_2() << '\n';
        std::cout << "num2 / num1 = " << calculator.divide_2_1() << '\n';

        num1IsNotZero = false;
        num2IsNotZero = false;
    }

    return 0;
}
