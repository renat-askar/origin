#include <iostream>
#include <initializer_list>

class get
{
    int* array{};
    size_t size{};

    public:
        get(std::initializer_list<int> initList)
        {
            array = new int[initList.size()]{};
            size = initList.size();
            auto init{initList.begin()};
            for(int* iter{array}; iter < &array[size]; ++iter, ++init)
            {
                *iter = *init;
            }
        }

        enum set{sum, count};
        set set_get{};
        void set_get_count(set set_get_count)
        {
            switch(set_get_count)
            {
                case sum: set_get = sum; break;
                case count: set_get = count; break;
            }
        }

        size_t get_size() const {return size;}

        int get_sum()
        {
            int sum{};
            for(int* iter{array}; iter < &array[size]; ++iter)
                sum += *iter;
            return sum;
        }

        int get_count()
        {
            int count{};
            for(int* iter{array}; iter < &array[size]; ++iter)
                if(*iter % 3) ++count;
            return count;
        }

        int operator[](size_t idx){if(idx >= size) std::exception{}; return array[idx];}

        int operator()()
        {   
            switch(set_get)
            {
                case sum: return get_sum();
                case count: return get_count();
                default: return get_sum();
            }
        }
};

int main()
{
    get numbers{4, 1, 3, 6, 25, 54};
    std::cout << "[IN]: " << numbers[0];
    for(size_t idx{1}; idx < numbers.get_size(); ++idx)
    {
        std::cout << ' ' << numbers[idx];
    }
    std::cout << '\n';

    std::cout << "[OUT]: get_sum() = " << numbers() << '\n';

    numbers.set_get_count(get::count);

    std::cout << "[OUT]: get_count() = " << numbers() << '\n';

    return 0;
}
