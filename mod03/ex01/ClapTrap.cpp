#include "ClapTrap.hpp"

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Constructor / Destructor sırası
//   Nesne yaratılırken constructor, yok edilirken destructor çalışır.
//   Çıktıyı izleyerek nesne yaşam döngüsünü takip edebilirsin.
// ─────────────────────────────────────────────────────────────────────────────

// Default constructor — isim verilmezse "unnamed" kullan
ClapTrap::ClapTrap()
    : _name("unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "[ClapTrap] Default constructor called for " << _name << std::endl;
}

// Parametreli constructor — dışarıdan isim alır, sabit başlangıç değerleri atar
ClapTrap::ClapTrap(std::string const & name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "[ClapTrap] Constructor called for " << _name << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Copy constructor
//   Var olan bir nesneden YENİ nesne üretir. Deep copy gerekirse burada yapılır.
//   Burada string ve int'ler value type olduğu için shallow copy yeterli.
// ─────────────────────────────────────────────────────────────────────────────
ClapTrap::ClapTrap(ClapTrap const & src)
{
    std::cout << "[ClapTrap] Copy constructor called for " << src._name << std::endl;
    *this = src; // assignment operator'ı çağırır, kod tekrarını önler
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Copy assignment operator (operator=)
//   Var olan nesneye başka bir nesnenin değerlerini kopyalar.
//   Self-assignment kontrolü (if this != &rhs) şart!
// ─────────────────────────────────────────────────────────────────────────────
ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
    if (this != &rhs) // kendine atama kontrolü: a = a durumunu önler
    {
        _name         = rhs._name;
        _hitPoints    = rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this; // zincirleme atamaya izin verir: a = b = c
}

// Destructor — nesne scope'tan çıkınca otomatik çalışır
ClapTrap::~ClapTrap()
{
    std::cout << "[ClapTrap] Destructor called for " << _name << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Member function — kaynak tüketimi kontrolü
//   Her aksiyon öncesi HP ve enerji kontrolü yapılır.
//   Oyun mekaniğini simüle ederken koşullu mantık alıştırması olur.
// ─────────────────────────────────────────────────────────────────────────────

void    ClapTrap::attack(std::string const & target)
{
    // Enerji veya HP yoksa saldıramaz
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "[ClapTrap] " << _name
                  << " can't attack! No energy or HP left." << std::endl;
        return;
    }
    _energyPoints--; // her saldırı 1 enerji tüketir
    std::cout << "[ClapTrap] " << _name
              << " attacks " << target
              << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints <= 0)
    {
        std::cout << "[ClapTrap] " << _name << " is already dead!" << std::endl;
        return;
    }
    _hitPoints -= static_cast<int>(amount); // unsigned → int cast, negatife düşebilir
    if (_hitPoints < 0)
        _hitPoints = 0; // HP 0'ın altına inmez
    std::cout << "[ClapTrap] " << _name
              << " takes " << amount << " damage! HP: " << _hitPoints << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0 || _energyPoints <= 0)
    {
        std::cout << "[ClapTrap] " << _name
                  << " can't repair! No energy or HP left." << std::endl;
        return;
    }
    _energyPoints--;   // repair de enerji tüketir
    _hitPoints += static_cast<int>(amount);
    std::cout << "[ClapTrap] " << _name
              << " repairs itself for " << amount << " HP! HP: " << _hitPoints << std::endl;
}
