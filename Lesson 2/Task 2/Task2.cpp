#include <iostream>
#include <exception>

class smart_array
{
    int* array{};
    size_t size{};

    public:
        smart_array(size_t initSize)
        {
            array = new int[initSize]{};
        }

        void add_element(int element)
        {
            array[size++] = element;
        }

        int get_element(size_t idx) const
        {
            if(idx >= size)
                throw std::exception{};
            return array[idx];
        }

        ~smart_array()
        {
            delete[] array;
        }
};

int main()
{
    try
    {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(1) << std::endl;
    }
    catch(const std::exception& ex)
    {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}