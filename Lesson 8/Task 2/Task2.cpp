#include <iostream>
#include <string>
#include <utility>

class big_integer
{
    std::string number{};

    public:
        big_integer(const std::string& num): number{num}{};

        big_integer(big_integer&& big_int) noexcept: number{std::move(big_int.number)}{}

        big_integer& operator = (big_integer&& big_int) noexcept
        {
            number = std::move(big_int.number);
            big_int.number = "0";
            return *this;
        }

        std::string operator + (const big_integer& big_int)
        {
            return std::to_string(std::stoi(number) + std::stoi(big_int.number));
        }

        std::string operator * (const big_integer& big_int)
        {
            return std::to_string(std::stoi(number) * std::stoi(big_int.number));
        }
};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result;

    return 0;
}
