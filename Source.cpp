/*#include <iostream>
#include <string>
#include <map>

#include "Header.h"

void Basket::add(std::string& article, unsigned int quantity)
{
	basket[article] += quantity;    
}

void Basket::remove(std::string& article, unsigned int quantity)
{
    if (basket.find(article) == basket.end()) throw ArticleIsNotPresent();

    if (basket[article] < quantity) throw ExceedingQuantity();

    basket[article] -= quantity;

    if (!basket[article]) basket.erase(article);
}

void Basket::output() const
{
    std::cout << "\nBasket:\n";
    
    for (auto const& elem : basket)
    {
        std::cout << elem.first << ": " << elem.second << '\n';
    }
}*/