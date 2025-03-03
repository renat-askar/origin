#include <iostream>
#include <vector>
#include <set>

void unique(std::vector<int>& vec)
{
    std::set<int> set{};
    for(const auto& e: vec)
    {
        set.emplace(e);
    }

    auto iter1{vec.begin()};
    for(auto iter2{set.begin()}; iter2 != set.end(); ++iter2, ++iter1)
    {
        *iter1 = *iter2;
    }
    vec.erase(iter1, vec.end());
}

int main()
{
    std::vector<int> vec{1, 1, 2, 5, 6, 1, 2, 4};

    std::cout << "[IN]: " << *vec.cbegin();
    for(auto iter{++vec.cbegin()}; iter != vec.cend(); ++iter)
    {
        std::cout << ' ' << *iter;
    }
    std::cout << '\n';

    unique(vec);

    std::cout << "[OUT]: " << *vec.cbegin();
    for(auto iter{++vec.cbegin()}; iter != vec.cend(); ++iter)
    {
        std::cout << ' ' << *iter;
    }
    std::cout << '\n';

    return 0;
}