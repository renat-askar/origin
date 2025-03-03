#include <iostream>
#include <set>

template<typename Type>
void print(std::set<Type> set)
{
    std::cout << *set.cbegin();
    for(auto iter{++set.cbegin()}; iter != set.cend(); ++iter)
    {
        std::cout << ' ' << *iter;
    }
}

int main()
{
    std::set<std::string> test_set = {"one", "two", "three", "four"};
    print(test_set);

    return 0;
}
