#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    // OCF
    Fixed();
    Fixed(const int n);
    Fixed(const float f);
    Fixed(const Fixed& other);
    Fixed& operator=(const Fixed& other);
    ~Fixed();

    // Dönüşüm
    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;

    // Karşılaştırma operatörleri — bool döndürür
    bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

    // Aritmetik operatörler — yeni Fixed döndürür
    Fixed operator+(const Fixed& other) const;
    Fixed operator-(const Fixed& other) const;
    Fixed operator*(const Fixed& other) const;
    Fixed operator/(const Fixed& other) const;

    // Prefix: ++a, --a — önce artır, sonra döndür
    Fixed& operator++();
    Fixed& operator--();

    // Postfix: a++, a-- — önce döndür, sonra artır (int dummy parametre)
    Fixed operator++(int);
    Fixed operator--(int);

    // En küçük / en büyüğü döndür — static çünkü nesneye ihtiyaç yok
    static Fixed&       min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed&       max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif