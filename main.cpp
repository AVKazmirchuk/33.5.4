//#include <iostream>
//#include <vector>

/*#include "Header.h"

bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid data!\n";
        return false;
    }
    else
    {
        if (std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid data!\n";
            return false;
        }
    }

    return true;
}

void adding(Basket& basket)
{
    std::cout << "To add, enter the article and quantity, (book 10). To finish typing, type 0 0\n\n";

    std::string article;
    unsigned int quantity;

    while (true)
    {
        std::cin >> article >> quantity;

        if (!cinNoFail()) continue;

        if (article == "0") break;
        basket.add(article, quantity);
    }
}

void removal(Basket& basket)
{
    std::cout << "\nTo delete, enter the article and quantity, (book 10). To finish typing, type 0 0\n\n";

    std::string article;
    unsigned int quantity;

    while (true)
    {
        std::cin >> article >> quantity;

        if (!cinNoFail()) continue;

        if (article == "0") break;

        try
        {
            basket.remove(article, quantity);
        }
        catch (const ArticleIsNotPresent& e)
        {
            std::cout << e.what();
            continue;
        }
        catch (const ExceedingQuantity& e)
        {
            std::cout << e.what();
            continue;
        }
    }
}

int main()
{
    Basket basket;

    adding(basket);

    basket.output();

    removal(basket);

    basket.output();
}*/

#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
//#include <type_traits>

template <typename T>
void input(const T& container, long double size = 0)
{

}


template <typename T>
auto arithmeticMean(const T& container, long double size = 0)
{
    long double tmp{};

    if constexpr (!std::is_array_v<T> && !std::is_pointer_v<T>)
    {
        if constexpr (std::is_same_v<T, std::forward_list<typename T::value_type>>) size = std::distance(container.begin(), container.end());
        else size = container.size();

        for (const auto& elem : container)
        {
            tmp += elem / size;
            std::cout << tmp << " ";
        }
    }
    else
    {
        std::cout << "array:\n";

        if (std::is_array_v<T>) size = std::extent_v<T>;

        for (int i{}; i < size; ++i)
        {
            tmp += container[i] / size;
            std::cout << tmp << " ";
        }
    }

    

    return tmp;
}

int main()
{
    
    
    
    
    
    std::array<int, 9> a{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(a) << '\n';

    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(v) << '\n';

    std::deque<int> d{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(d) << '\n';

    std::list<int> l{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(l) << '\n';

    std::forward_list<int> fl{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(fl) << '\n';

    std::set<int> s{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(s) << '\n';

    std::multiset<int> ms{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(ms) << '\n';

    std::unordered_set<int> us{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(us) << '\n';

    std::unordered_multiset<int> us{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(us) << '\n';

    int as[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(as) << '\n';

    int* ad = new int[9]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(ad, 9) << '\n';
    delete[] ad;


}