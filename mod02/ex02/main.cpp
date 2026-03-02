#include "Fixed.hpp"

int main(void) {
    Fixed a(10);
    Fixed b(5.5f);
    Fixed c(2);

    // Karşılaştırma
    std::cout << "a > b  : " << (a > b)  << std::endl;  // 1
    std::cout << "a < b  : " << (a < b)  << std::endl;  // 0
    std::cout << "a == a : " << (a == a) << std::endl;  // 1
    std::cout << "a != b : " << (a != b) << std::endl;  // 1

    std::cout << std::endl;

    // Aritmetik
    std::cout << "a + b = " << (a + b) << std::endl;  // 15.5
    std::cout << "a - b = " << (a - b) << std::endl;  // 4.5
    std::cout << "a * c = " << (a * c) << std::endl;  // 20
    std::cout << "a / c = " << (a / c) << std::endl;  // 5

    std::cout << std::endl;

    // Increment / Decrement
    Fixed d(1);
    std::cout << "d      = " << d   << std::endl;  // 1
    std::cout << "d++    = " << d++ << std::endl;  // 1 (eski değer)
    std::cout << "d      = " << d   << std::endl;  // 1.00391 (1 + 1/256)
    std::cout << "++d    = " << ++d << std::endl;  // 1.00781 (artırılmış)

    std::cout << std::endl;

    // Min / Max
    std::cout << "min(a,b) = " << Fixed::min(a, b) << std::endl;  // 5.5
    std::cout << "max(a,b) = " << Fixed::max(a, b) << std::endl;  // 10

    return 0;
}