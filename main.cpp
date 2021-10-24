#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>
#include <tuple>
//#include <type_traits>

bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //std::cout << "Invalid data!\n";
        return false;
    }
    else
    {
        if (std::cin.peek() != '\n')
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            //std::cout << "Invalid data!\n";
            return false;
        }
    }
    return true;
}

template <typename T>
void checkInput(T& elem)
{
    while (true)
    {
        std::make_signed_t<std::decay_t<T>> tmp;

        std::cin >> tmp;

        if (cinNoFail())
        {
            if (std::is_unsigned_v<std::decay_t<T>> && tmp < 0)
            {
                std::cout << "You entered a negative number!\n";
                continue;
            }

            elem = tmp;
            break;
        }

        std::cout << "Type mismatch!\n";
    }
}

template <typename T, size_t size>
void input(std::array<T, size>& container)
{
    for (auto& elem : container)
    {
        checkInput(elem);
    }
}

template <typename T>
void input(T* container, long long size)
{
    T elem{};
    
    for (int i{}; i < size; ++i)
    {
        checkInput(elem);
        container[i] = elem;
    }
}

template <typename T>
void input(T& container)
{
    long long size;

    while (true)
    {
        std::cout << "Number of items in the container: ";

        std::cin >> size;

        if (cinNoFail())
        {

            break;
        }
        std::cout << "Invalid data!\n";
    }

    typename T::value_type elem{};

    if constexpr (std::is_same_v<T, std::forward_list<typename T::value_type>>)
    {
        for (int i{}; i < size; ++i)
        {
            checkInput(elem);
            container.push_front(elem);
        }
    }
    else if constexpr (std::is_same_v<T, std::set<typename T::value_type>> || 
        std::is_same_v<T, std::multiset<typename T::value_type>> || 
        std::is_same_v<T, std::unordered_set<typename T::value_type>> || 
        std::is_same_v<T, std::unordered_multiset<typename T::value_type>>)
    {
        for (int i{}; i < size; ++i)
        {
            checkInput(elem);
            container.insert(elem);
        }
    }
    else
    {
        for (int i{}; i < size; ++i)
        {
            checkInput(elem);
            container.push_back(elem);
        }
    }
}

template <typename T>
auto arithmeticMean(const T* container, long long size)
{
    long double tmp{};

    for (int i{}; i < size; ++i)
    {
        tmp += static_cast<long double>(container[i]) / size;
        std::cout << tmp << " ";
    }

    if constexpr (std::is_same_v<T, char*>) return static_cast<char>(tmp);
    else return tmp;
}

template <typename T>
auto arithmeticMean(const T& container)
{
    long double tmp{};
    size_t size;
       
    if constexpr (std::is_same_v<T, std::forward_list<typename T::value_type>>) size = std::distance(container.begin(), container.end());
    else size = container.size();

    for (const auto& elem : container)
    {
        tmp += static_cast<long double>(elem) / size;
        std::cout << tmp << " ";
    }
       
    if constexpr (std::is_same_v<typename T::value_type, char>) return static_cast<char>(tmp);
    else return tmp;
}

int main()
{
    /*std::array<char, 9> a2;
    input(a2);
    std::cout << arithmeticMean(a2) << '\n';*/

    /*std::vector<int> v2{};
    input(v2);
    std::cout << arithmeticMean(v2) << '\n';*/

    /*std::deque<int> d2;
    input(d2);
    std::cout << arithmeticMean(d2) << '\n';*/

    /*std::list<int> l2;
    input(l2);
    std::cout << arithmeticMean(l2) << '\n';*/

    /*std::forward_list<int> fl2;
    input(fl2);
    std::cout << arithmeticMean(fl2) << '\n';*/

    /*std::set<int> s2;
    input(s2);
    std::cout << arithmeticMean(s2) << '\n';*/

    /*std::multiset<int> ms2;
    input(ms2);
    std::cout << arithmeticMean(ms2) << '\n';*/

    /*std::unordered_set<int> us2;
    input(us2);
    std::cout << arithmeticMean(us2) << '\n';*/

    /*std::unordered_multiset<int> ums2;
    input(ums2);
    std::cout << arithmeticMean(ums2) << '\n';*/

    /*int as2[9]{};
    input(as2, 9);
    std::cout << arithmeticMean(as2, 9) << '\n';*/

    int* ad2 = new int[9]{};
    input(ad2, 9);
    std::cout << arithmeticMean(ad2, 9) << '\n';
    delete[] ad2;



    /*std::array<int, 9> a{ 1.1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(a) << '\n';

    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    input(v);
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

    std::unordered_multiset<int> ums{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(ums) << '\n';

    int as[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(as, 9) << '\n';

    /*int* ad = new int[9]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(ad, 9) << '\n';
    delete[] ad;*/


}
