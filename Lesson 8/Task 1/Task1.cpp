#include <vector>

template<typename Type>
void move_vectors(std::vector<Type>& vec1, std::vector<Type>& vec2)
{
    vec2 = std::move(vec1);
}
