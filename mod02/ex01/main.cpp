#include "Fixed.hpp"

int main(void) {
    Fixed a;                  // default constructor → _value = 0
    Fixed b(10);              // int constructor    → _value = 10 * 256 = 2560
    Fixed c(42.42f);          // float constructor  → _value = roundf(42.42 * 256) = 10859
    Fixed d(b);               // copy constructor   → _value = 2560

    std::cout << "a = " << a << std::endl;  // 0
    std::cout << "b = " << b << std::endl;  // 10
    std::cout << "c = " << c << std::endl;  // 42.4219 (float hassasiyeti)
    std::cout << "d = " << d << std::endl;  // 10

    std::cout << "b.toInt()   = " << b.toInt()   << std::endl;  // 10
    std::cout << "c.toFloat() = " << c.toFloat() << std::endl;  // 42.4219

    std::cout << "b.getRawBits() = " << b.getRawBits() << std::endl;  // 2560
    std::cout << "c.getRawBits() = " << c.getRawBits() << std::endl;  // 10859

    return 0;
}
