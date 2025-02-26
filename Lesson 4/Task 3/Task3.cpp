#include <iostream>

class get
{
    int* array{};
    size_t size{};

    public:
        enum set_sum_count{sum, count};

        get(int* initArray, size_t initSize): array{initArray}, size{initSize}{}
        
        int operator()(set_sum_count set)
        {   
            switch(set)
            {
                case sum: return get_sum();
                case count: return get_count();
                default: return get_sum();
            }
        }

        int get_sum()
        {
            int sum{};
            for(int* iter{array}; iter < &array[size]; ++iter)
                if(*iter % 3 == 0) sum += *iter;
            return sum;
        }

        int get_count()
        {
            int count{};
            for(int* iter{array}; iter < &array[size]; ++iter)
                if(*iter % 3 == 0) ++count;
            return count;
        }
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

    get get_sum_count{array, size};

    std::cout << "[OUT]: get_sum() = " << get_sum_count(get::sum) << '\n';
    std::cout << "[OUT]: get_count() = " << get_sum_count(get::count) << '\n';

    return 0;
}
