#include "BigInt.hpp"
#include <iostream>

BigInt fibonacci(int n)
{
    BigInt a = 1;
    BigInt b = 1;
    BigInt placeholder;
    for (int index = 2; index < n; index++)
    {
        placeholder = a;
        a += b;
        b = placeholder;
    }
    return a;
}

int main()
{
    BigInt a = "123456789";
    BigInt b = "-123456789";
    BigInt c = a + b;
    a *= b;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    b = fibonacci(500);
    std::cout << b;
}
