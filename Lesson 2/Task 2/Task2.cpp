#include <iostream>
#include <exception>

class smart_array
{
    int* array{};
    size_t size{};
    size_t capacity{};

    public:
        smart_array(size_t initSize): capacity{initSize}
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

        size_t getCapacity() const
        {
            return capacity;
        }

        size_t getSize() const
        {
            return size;
        }

        void operator = (const smart_array& arr)
        {
            delete[] array;
            array = new int[arr.getCapacity()]{};
            size = arr.getSize();
            capacity = arr.getCapacity();
            for(size_t idx{}; idx < arr.getCapacity(); ++idx)
            {
                array[idx] = arr.get_element(idx);
            }
        }

        ~smart_array()
        {
            delete[] array;
        }
};

int main()
{
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44); 
    new_array.add_element(34);

    arr = new_array;

    return 0;
}
