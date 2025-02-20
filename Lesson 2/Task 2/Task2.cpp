#include <iostream>
#include <exception>

class smart_array
{
    int* array{};
    size_t size{};
    size_t capacity{};

    public:
        smart_array(size_t initCapacity): capacity{initCapacity}
        {
            array = new int[initCapacity]{};
        }

        void operator = (const smart_array& arr)
        {
            delete[] array;
            array = new int[arr.getCapacity()]{};
            size = 0;
            capacity = arr.getCapacity();
            for(size_t idx{}; idx < arr.getSize(); ++idx)
            {
                add_element(arr.get_element(idx));
            }
        }

        size_t getSize() const {return size;}
        size_t getCapacity() const {return capacity;}

        void add_element(int element)
        {
            if(size >= capacity)
            {
                int* temp{array};
                array = new int[capacity *= 2]{};
                for(size_t idx{}; idx < size; ++idx)
                {
                    array[idx] = temp[idx];
                }
                delete[] temp;
            }
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
