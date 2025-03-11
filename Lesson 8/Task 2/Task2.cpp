#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <vector>

class big_integer
{
    std::string number{};

    public:
        big_integer(const std::string& num): number{num}{};

        big_integer(big_integer&& big_int) noexcept: number{std::move(big_int.number)}{}

        big_integer& operator = (big_integer&& big_int)
        {
            number = std::move(big_int.number);
            big_int.number = "0";
            return *this;
        }

        std::string operator + (const big_integer& big_int)
        {
            std::string number1{number};
            std::string number2{big_int.number};
            
            if(number1.length() > number2.length())
                std::swap(number1, number2);

            std::string number{};

            size_t n1{number1.length()};
            size_t n2{number2.length()};

            std::reverse(number1.begin(), number1.end());
            std::reverse(number2.begin(), number2.end());

            int carry{0};
            for(size_t idx{}; idx < n1; ++idx)
            {
                int sum{(number1[idx] - '0') + (number2[idx] - '0') + carry};
                number.push_back(sum % 10 + '0');

                carry = sum / 10;
            }
            
            for(size_t idx{n1}; idx < n2; ++idx)
            {
                int sum{(number2[idx] - '0') + carry};
                number.push_back(sum % 10 + '0');
                carry = sum / 10;
            }

            if(carry)
                number.push_back(carry + '0');

            std::reverse(number.begin(), number.end());

            return number;
        }

        std::string operator * (const big_integer& big_int)
        {
            std::vector<int> vec1(number.size());
            for(size_t idx{}; idx < number.size(); ++idx)
            {
                vec1[idx] = number[number.size() - idx - 1] - '0';
            }
            std::vector<int> vec2(big_int.number.size());
            for(size_t idx{}; idx < big_int.number.size(); ++idx)
            {
                vec2[idx] = big_int.number[big_int.number.size() - idx - 1] - '0';
            }

            std::vector<int> result(vec1.size() + vec2.size());

            for(size_t idx{}; idx < vec2.size(); ++idx)
            {
                int carry{};
                for(size_t jdx{}; jdx < vec1.size(); ++jdx)
                {
                    int product{vec1[jdx] * vec2[idx] + carry + result[idx + jdx]};
                    carry = product / 10;
                    result[idx + jdx] = product % 10;
                }
                result[idx + vec1.size()] = carry;
            }

            while(result.size() > 1 && result.back() == 0)
            {
                result.pop_back();
            }

            std::string str(result.size(), '0');
            for(size_t idx{}; idx < result.size(); ++idx)
            {
                str[result.size() - idx - 1] = result[idx] + '0';
            }
            return str;
        }

        std::string operator * (int num)
        {
            std::string numstr{std::to_string(num)};
            std::vector<int> vec1(number.size());
            for(size_t idx{}; idx < number.size(); ++idx)
            {
                vec1[idx] = number[number.size() - idx - 1] - '0';
            }
            std::vector<int> vec2(numstr.size());
            for(size_t idx{}; idx < numstr.size(); ++idx)
            {
                vec2[idx] = numstr[numstr.size() - idx - 1] - '0';
            }

            std::vector<int> result(vec1.size() + vec2.size());

            for(size_t idx{}; idx < vec2.size(); ++idx)
            {
                int carry{};
                for(size_t jdx{}; jdx < vec1.size(); ++jdx)
                {
                    int product{vec1[jdx] * vec2[idx] + carry + result[idx + jdx]};
                    carry = product / 10;
                    result[idx + jdx] = product % 10;
                }
                result[idx + vec1.size()] = carry;
            }

            while(result.size() > 1 && result.back() == 0)
            {
                result.pop_back();
            }

            std::string str(result.size(), '0');
            for(size_t idx{}; idx < result.size(); ++idx)
            {
                str[result.size() - idx - 1] = result[idx] + '0';
            }
            return str;
        }
};

int main()
{
    auto number1 = big_integer("114575");
    auto number2 = big_integer("78524");
    auto result = number1 + number2;
    std::cout << result << '\n';

    return 0;
}
