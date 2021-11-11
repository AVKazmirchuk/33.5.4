#include <iostream>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <unordered_set>



bool cinNoFail()
{
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }

    return true;
}

//Функция ввода элемента и проверки совпадения типа элементов и вводимых данных (знаковый/беззнаковый)
template <typename T>
void checkInput(T& elem)
{
    while (true)
    {
        std::make_signed_t<std::decay_t<T>> tmp{};

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

/*//Ввод данных для std::array
template <typename T, size_t size>
void input(std::array<T, size>& container)
{
    std::cout << "Enter the array elements:\n";

    for (auto& elem : container)
    {
        checkInput(elem);
    }
}*/

void enterSize(unsigned long long& size)
{
    while (true)
    {
        std::cout << "Number of items in the container: ";

        std::cin >> size;

        if (cinNoFail() && size > 0)
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
        std::cout << "Invalid data!\n";
    }
}

//Ввод данных (основная функция) для статических массивов
template <typename T>
void input(T container[], unsigned long long&& size, const char* name)
{
    T elem{};

    std::cout << name << "! Number of items in the container: " << size << '\n';

    std::cout << "Enter the array elements: ";

    for (int i{}; i < size; ++i)
    {
        checkInput(elem);
        container[i] = elem;
    }
}

//Ввод данных (основная функция) для динамических массивов
template <typename T>
void input(T*& container, unsigned long long& size, const char* name)
{
    T elem{};

    std::cout << name << "!\n";

    enterSize(size);

    container = new T[size];

    std::cout << "Enter the array elements: ";

    for (int i{}; i < size; ++i)
    {
        checkInput(elem);
        container[i] = elem;
    }
}

/*//Ввод данных для контейнеров STL, одинаково не для всех (в условии ниже понятно), так как они имеют разные функции ввода
template <typename T>
void input(T& container, const char* name)
{
    unsigned long long size;

    while (true)
    {
        std::cout << "Number of items in the container: ";

        std::cin >> size;

        if (cinNoFail() && size > 0)
        {
            break;
        }
        std::cout << "Invalid data!\n";
    }

    typename T::value_type elem{};

    std::cout << "Enter the array elements: ";

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
}*/

//Вычисление среднего арифметического для обычных и динамических массивов
template <typename T>
auto arithmeticMean(const T* container, const unsigned long long size)
{
    long double tmp{};

    for (int i{}; i < size; ++i)
    {
        //Решил каждый элемент вначале делить на размер, а потом складывать результат, для избежания переполнения
        tmp += static_cast<long double>(container[i]) / size;
        std::cout << tmp << " ";
    }

    //Для типа char необходимо "среднюю" преобразовать к его типу, так как результат совсем неверный
    if constexpr (std::is_same_v<T, char*>) return static_cast<char>(tmp);
    else return tmp;
}

/*//Вычисление среднего арифметического для контейнеров STL
template <typename T>
auto arithmeticMean(const T& container)
{
    long double tmp{};
    size_t size;

    //std::forward_list не имеет параметра размера, поэтому необходимо вычислить его для унификации функции
    if constexpr (std::is_same_v<T, std::forward_list<typename T::value_type>>) size = std::distance(container.begin(), container.end());
    else size = container.size();

    for (const auto& elem : container)
    {
        //Решил каждый элемент вначале делить на размер, а потом складывать результат, для избежания переполнения
        tmp += static_cast<long double>(elem) / size;
        std::cout << tmp << " ";
    }

    //Для типа char необходимо "среднюю" преобразовать к его типу, так как результат совсем неверный
    if constexpr (std::is_same_v<typename T::value_type, char>) return static_cast<char>(tmp);
    else return tmp;
}*/

int main()
{
    //Для тестирования всех контейнеров
    //Контейнер или группа контейнеров использует свою шаблонную функцию
    //С функцией ввода данных

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

    int as2[9]{};
    input(as2, 9, "static mass");
    std::cout << "\nArithmetic mean: " << arithmeticMean(as2, 9) << "\n\n";

    char* ad2{ nullptr };
    unsigned long long size{};
    input(ad2, size, "dynamic mass");
    std::cout << "\nArithmetic mean: " << arithmeticMean(ad2, size) << "\n\n";
    delete[] ad2;

   

    //Для тестирования всех контейнеров
    //Контейнер или группа контейнеров использует свою шаблонную функцию

    /*
    std::array<int, 9> a{ 1.1, 2, 3, 4, 5, 6, 7, 8, 9 };
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

    std::unordered_multiset<int> ums{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(ums) << '\n';

    int as[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(as, 9) << '\n';

    int* ad = new int[9]{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(ad, 9) << '\n';
    delete[] ad;
    */
}
