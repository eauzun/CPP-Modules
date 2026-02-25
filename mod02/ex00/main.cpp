#include <iostream>
#include "Fixed.hpp"

int main( void )
{
    Fixed a;
    Fixed b( a );
    Fixed c;
    c = b;

    std::cout << a.getBits() << std::endl;
    std::cout << b.getBits() << std::endl;
    std::cout << c.getBits() << std::endl;

    return 0;
}