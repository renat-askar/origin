#include <iostream>
#include <vector>

template<typename Type>
std::ostream& operator << (std::ostream& out, std::vector<Type> vec)
{
    if(vec.empty()) return out;
    std::cout << vec[0];
    for(Type* iter{&vec[1]}; iter < &vec[vec.size()]; ++iter)
    {
        std::cout << ", " << *iter;
    }
    return out;
}

template<typename Type>
Type square(Type num)
{
    return num * num;
}

template<typename Type>
std::vector<Type> square(std::vector<Type> vec)
{
    for(auto& e: vec)
        e *= e;
    return vec;
}

int main()
{
    int num{4};
    std::vector<int> vec{-1, 4, 8};
    std::cout << "[IN]: " << num << '\n';
    std::cout << "[OUT]: " << square(num) << '\n';
    std::cout << "[IN]: " << vec << '\n';
    std::cout << "[OUT]: " << square(vec) << '\n';

    return 0;
}
