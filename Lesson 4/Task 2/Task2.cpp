#include <iostream>

template<class Type>
class Table
{
    int** table{};
    size_t rows{};
    size_t cols{};

    public:
        class Array
        {
            Type* array{};

            public:
                Array(Type* array): array{array}{}

                Type& operator[](size_t idx){return array[idx];}
        };

        Table(size_t rows, size_t cols): rows{rows}, cols{cols}
        {
            table = new Type*[rows]{};
            for(int idx{}; idx < rows; ++idx)
                table[idx] = new Type[cols]{};
        }

        Array operator[](size_t idx) const {return Array{table[idx]};}

        size_t Size() const {return sizeof(Type) * cols * rows;}
};

int main()
{
    auto test{Table<int>(2, 3)};
    test[0][0] = 4;
    std::cout << test[0][0] << '\n';

    return 0;
}
