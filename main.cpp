#include <iostream>
#include <array>
#include <vector>

template <class T>
auto arithmeticMean(const T& container, long double size = 0)
{
    long double tmp{};

    if constexpr (!std::is_array_v<T> && !std::is_pointer_v<T>)
    {
        size = container.size();
    }
    else
    {
        std::cout << "array:\n";
        
        if (std::is_array_v<T>) size = std::extent_v<T>;
    }

    for (int i{}; i < size; ++i)
    {
        tmp += container[i] / size;
        std::cout << tmp << " ";
    }

    return tmp;
}

int main()
{
    std::array<int, 9> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(a) << '\n';


    
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(v) << '\n';

    

    

    int ms[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(ms) << '\n';

    int* md = new int[9] { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(md, 9) << '\n';
    delete[] md;

    
}