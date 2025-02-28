#include <iostream>
#include <set>

int main()
{
    size_t size{};
    std::cout << "[IN]:\n";
    std::cin >> size;

    std::set<int, std::greater<int>> list{};
    for(int count{}, push{}; count < size; ++count)
    {
        std::cin >> push;
        list.emplace(push);
    }

    std::cout << "[OUT]:\n";
    for(const auto& e: list)
    {
        std::cout << e << '\n';
    }

    return 0;
}
