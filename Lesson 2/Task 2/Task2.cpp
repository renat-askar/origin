#include "Windows.h"

#include <iostream>
#include <string>

class Counter
{
    int count{1};

    public:
        Counter() = default;
        Counter(int initial): count{initial}{}

        const int get() const
        {
            return count;
        }
        void decrease()
        {
            --count;
        }
        void increase()
        {
            ++count;
        }
};

int main()
{
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    bool isInitial{};
    std::string select{};
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> select;

    if(select == "да") isInitial = true;
    else isInitial = false;

    if(isInitial)
    {
        int count{};
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> count;

        char selector{};
        Counter counter{count};
        while(selector != 'x')
        {
            std::cout << "Введите команду ('+', '-', '=', или 'x'): ";
            std::cin >> selector;

            switch(selector)
            {
                case '+': counter.increase(); break;
                case '-': counter.decrease(); break;
                case '=': std::cout << counter.get(); break;
                case 'x': std::cout << "До свидания!\n"; break;
            }
        }
    }
    else
    {
        char selector{};
        Counter counter{};
        while(selector != 'x')
        {
            std::cout << "Введите команду ('+', '-', '=', или 'x'): ";
            std::cin >> selector;

            switch(selector)
            {
                case '+': counter.increase(); break;
                case '-': counter.decrease(); break;
                case '=': std::cout << counter.get() << '\n'; break;
                case 'x': std::cout << "До свидания!\n"; break;
            }
        }
    }

    return 0;
}
