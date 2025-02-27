#include <iostream>

class get
{
    int sum{};
    int count{};

    public:        
        void operator()(int number)
        {   
            if(number % 3 == 0)
            {
                sum += number;
                ++count;
            }
        }

        int get_sum() const {return sum;}
        int get_count() const {return count;}
};

int main()
{
    const size_t size{6};
    int array[size]{4, 1, 3, 6, 25, 54};
    std::cout << "[IN]: " << *array;
    for(int* iter{&1[array]}; iter < &array[size]; ++iter)
    {
        std::cout << ' ' << *iter;
    }
    std::cout << '\n';

    get get_sum_count{};
    for(const auto& num: array)
    {
        get_sum_count(num);
    }
    std::cout << "[OUT]: get_sum() = " << get_sum_count.get_sum() << '\n';
    std::cout << "[OUT]: get_count() = " << get_sum_count.get_count() << '\n';

    return 0;
}
