template <class C>
long double arithmeticMean(const C& container)
{
    
    using value_type = typename container::value_type;
    using key_type = std::remove_reference_t<decltype(std::declval<value_type>)>;
    key_type sum = 0;
    //long double sum{};
    long long count{};

    for (const auto& elem : container)
    {
        sum += elem;
        ++count;
    }

    return sum / count;
}

int main()
{
    std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(v) << '\n';

    int mass[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    std::cout << arithmeticMean(mass) << '\n';
}
