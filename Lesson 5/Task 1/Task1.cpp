#include <iostream>
#include <map>

int main()
{
    const char hello_world[]{"Hello world!!"};

    std::cout << "[IN]: " << hello_world << '\n';

    std::map<char, int> char_frequency{};
    for(const char* iter{hello_world}; *iter != '\0'; ++iter)
        ++char_frequency[*iter];

    std::multimap<int, char, std::greater<int>> char_frequency_sort{};
    for(const auto& [key, value]: char_frequency)
    {
        char_frequency_sort.insert({value, key});
    }

    std::cout << "[OUT]:\n";
    for(const auto& [key, value]: char_frequency_sort)
    {
        std::cout << key << ": " << value << '\n';
    }

    return 0;
}
