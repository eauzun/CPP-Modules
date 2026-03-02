#include"Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}
// Fixed classtaki fixed foksiyonu. "::" scope resolution operatoru ile fonksiyonun hangi classa ait oldugunu belirtiyoruz.
// _value'ye 0 atayarak default constructoru tanimliyoruz. initilizer list kullanarak _value'ye 0 atamasini yapiyoruz. 
// Bu sayede constructorun bodysi bos kalir ve daha temiz bir kod yazmis oluruz.

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}
// "const Fixed &other" parametressi ile Fixed nesnesini referens olarak alıyoruz.
//.Kopyalamıyoruz, direkt orijinal nesneye referans veriyoruz.
//*this = other; ifadesi ile kopyalama işlemi yapıyoruz. 
//Bu ifade, copy constructorun içinde assignment operatorunu çağırarak kopyalama işlemini gerçekleştirir.
// Bu sayede copy constructorun içinde assignment operatorunu çağırarak kopyalama işlemini gerçekleştirir.
//_value = other._value yazablilirdik ama operator= zaten bunu yapıyor.

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl; //Fixed& → nesneyi referans olarak döndürüyoruz. Böylece a = b = c zinciri çalışır.
    if (this != &other) //Kendi kendine atama "X=X" durumunu kontrol ediyoruz. Eğer this ve other aynı nesneyi gösteriyorsa, atama işlemi yapmıyoruz.
        this->_value = other._value;  //Asıl kopyalama işlemi burada gerçekleşiyor. this->_value, current nesnenin _value'sunu temsil ederken, other._value, kopyalanacak nesnenin _value'sunu temsil eder.
    return *this; //nesneyi döndürüyoruz. Böylece a = b = c zinciri çalışır.
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}
//Nesne ölünce otomatik çağrılır. Bu class'ta new ile aldığımız bir memory yok, bu yüzden sadece log basıyoruz.
//Pointer olsaydı burada delete yazardık.

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value; //this pointerı ile _value'ya erişiyoruz. this pointerı, current nesneyi temsil eder.
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}