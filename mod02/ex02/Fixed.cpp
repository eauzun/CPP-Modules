#include "Fixed.hpp"

// ─── OCF ────────────────────────────────────────────────────────────────────

Fixed::Fixed() : _value(0) {}

// int → fixed: n * 2^8
Fixed::Fixed(const int n) : _value(n << _fractionalBits) {}

// float → fixed: f * 256, en yakın int'e yuvarla
Fixed::Fixed(const float f) : _value(roundf(f * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other)
        _value = other._value;
    return *this;
}

Fixed::~Fixed() {}

// ─── DÖNÜŞÜM ────────────────────────────────────────────────────────────────

int Fixed::getRawBits(void) const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

// fixed → float: _value / 256.0f
float Fixed::toFloat(void) const {
    return (float)_value / (1 << _fractionalBits);
}

// fixed → int: ondalık kısmı at
int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

// ─── KARŞILAŞTIRMA ──────────────────────────────────────────────────────────
// _value'ları direkt karşılaştırıyoruz, ikisi de aynı scale'de

bool Fixed::operator>(const Fixed& other) const  { return _value > other._value; }
bool Fixed::operator<(const Fixed& other) const  { return _value < other._value; }
bool Fixed::operator>=(const Fixed& other) const { return _value >= other._value; }
bool Fixed::operator<=(const Fixed& other) const { return _value <= other._value; }
bool Fixed::operator==(const Fixed& other) const { return _value == other._value; }
bool Fixed::operator!=(const Fixed& other) const { return _value != other._value; }

// ─── ARİTMETİK ──────────────────────────────────────────────────────────────

// Toplama: _value'ları direkt topla (aynı scale'deler)
Fixed Fixed::operator+(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_value + other._value);
    return result;
}

// Çıkarma: aynı mantık
Fixed Fixed::operator-(const Fixed& other) const {
    Fixed result;
    result.setRawBits(_value - other._value);
    return result;
}

// Çarpma: _value * _value scale'i iki katlar, geri almak için >> 8
// örnek: 2.0 * 3.0 → _value=512, _value=768 → 512*768=393216 >> 8 = 1536 → 6.0
Fixed Fixed::operator*(const Fixed& other) const {
    Fixed result;
    result.setRawBits(((long long)_value * other._value) >> _fractionalBits);
    return result;
}

// Bölme: önce << 8 ile scale'i artır, sonra böl
// örnek: 6.0 / 2.0 → _value=1536, _value=512 → (1536<<8)/512 = 768 → 3.0
Fixed Fixed::operator/(const Fixed& other) const {
    Fixed result;
    result.setRawBits(((long long)_value << _fractionalBits) / other._value);
    return result;
}

// ─── INCREMENT / DECREMENT ───────────────────────────────────────────────────

// Prefix ++a: önce artır, sonra döndür
// en küçük fixed-point adım = 1 (raw _value'da 1 artış = 1/256 artış)
Fixed& Fixed::operator++() {
    _value++;
    return *this;
}

// Prefix --a: önce azalt, sonra döndür
Fixed& Fixed::operator--() {
    _value--;
    return *this;
}

// Postfix a++: önce mevcut değeri sakla, artır, eskiyi döndür
// (int) dummy parametresi prefix ile postfix'i ayırt etmek için
Fixed Fixed::operator++(int) {
    Fixed old(*this);   // mevcut değeri kopyala
    _value++;           // artır
    return old;         // eski değeri döndür
}

// Postfix a--: aynı mantık
Fixed Fixed::operator--(int) {
    Fixed old(*this);
    _value--;
    return old;
}

// ─── STATIC MIN / MAX ───────────────────────────────────────────────────────
// static: nesne olmadan çağrılabilir → Fixed::min(a, b)
// iki versiyon: biri const nesneler için, diğeri normal

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// ─── COUT ───────────────────────────────────────────────────────────────────

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}