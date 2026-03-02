#include"Fixed.hpp"

int main()
{
    Fixed a; //Default constructor çağrısı. _Value 0
    Fixed b(a); //Copy constructor çağrısı. a'yı kopyalar.
    Fixed c; //Tekrar Default constructor çağrısı 

    c = b; //Copy assignment operator çağrısı. b'yi c'ye atar.

    std::cout << a.getRawBits() << std::endl; //getRawBits member function çağrısı. a'nın _value'sunu döndürür.
    std::cout << b.getRawBits() << std::endl; //getRawBits
    std::cout << c.getRawBits() << std::endl; //getRawBits

    return 0;
}
