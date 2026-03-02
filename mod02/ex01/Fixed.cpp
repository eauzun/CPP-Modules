#include "Fixed.hpp"

// Default constructor — _value'yu 0 yap
Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

// Int constructor — n'i fixed-point'e çevir
// n * 2^8 = n * 256 = n << 8
// örnek: n=5 → _value = 5 * 256 = 1280
Fixed::Fixed(const int n) : _value(n << _fractionalBits) {
    std::cout << "Int constructor called" << std::endl;
}

// Float constructor — f'yi fixed-point'e çevir
// f * 2^8 = f * 256.0f
// roundf() → en yakın int'e yuvarla
// örnek: f=1.5f → _value = roundf(1.5 * 256) = roundf(384.0) = 384
Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits))) {
    std::cout << "Float constructor called" << std::endl;
}

// Copy constructor — diğer nesneyi kopyala
// *this = other diyerek assignment operator'ı kullanıyoruz, kod tekrarı yok
Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

// Assignment operator — sağdaki nesnenin _value'sunu sola kopyala
Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)             // self-assignment kontrolü: a = a durumunda bir şey yapma
        _value = other._value;      // pointer yok, sadece int, shallow copy yeterli
    return *this;                   // zincirleme için: a = b = c
}

// Destructor — bu class'ta new yok, sadece log basıyoruz
Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// Ham _value'yu döndür — const çünkü nesneyi değiştirmiyor
int Fixed::getRawBits(void) const {
    return _value;
}

// Ham _value'yu set et
void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// Fixed → float dönüşümü
// _value / 2^8 = _value / 256.0f
// örnek: _value=384 → 384 / 256.0f = 1.5f
float Fixed::toFloat(void) const {
    return (float)_value / (1 << _fractionalBits);
}

// Fixed → int dönüşümü
// _value >> 8 = _value / 256 (ondalık kısmı at)
// örnek: _value=384 → 384 >> 8 = 1
int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// cout << fixed dediğinde float olarak yazdır
// class dışında tanımlandı çünkü sol taraf ostream, Fixed değil
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;  // zincirleme için: cout << a << b
}
