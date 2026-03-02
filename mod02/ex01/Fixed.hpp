#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>                    // roundf() için

class Fixed {
private:
    int                 _value;             // raw fixed-point değeri tutan int
    static const int    _fractionalBits = 8; // tüm nesneler bu değeri paylaşır, değişmez

public:
    Fixed();                                // default constructor
    Fixed(const int n);                     // int'ten Fixed oluştur
    Fixed(const float f);                   // float'tan Fixed oluştur
    Fixed(const Fixed& other);              // copy constructor
    Fixed& operator=(const Fixed& other);   // assignment operator
    ~Fixed();                               // destructor

    int     getRawBits(void) const;         // ham _value'yu döndür
    void    setRawBits(int const raw);      // ham _value'yu set et

    float   toFloat(void) const;            // Fixed → float dönüşümü
    int     toInt(void) const;              // Fixed → int dönüşümü
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed); // cout << fixed için

#endif
