#include "ScavTrap.hpp"

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Constructor zinciri (Constructor chaining)
//   ScavTrap constructor'ı initializer list'te ClapTrap(name) çağırır.
//   Bu sayede base class önce kurulur, sonra derived class kurulur.
//   SIRALAMA: ClapTrap() → ScavTrap()
// ─────────────────────────────────────────────────────────────────────────────

ScavTrap::ScavTrap()
    : ClapTrap()  // önce base'i kur
{
    // ScavTrap'e özgü başlangıç değerleri ClapTrap'inkinden farklı!
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "[ScavTrap] Default constructor called for " << _name << std::endl;
}

ScavTrap::ScavTrap(std::string const & name)
    : ClapTrap(name)  // base constructor'a ismi ilet — kendisi initialize etsin
{
    // ClapTrap zaten _name'i set etti, biz sadece stats'ı override ediyoruz
    _hitPoints    = 100;
    _energyPoints = 50;
    _attackDamage = 20;
    std::cout << "[ScavTrap] Constructor called for " << _name << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Derived class copy constructor
//   Kendi üyeleri yok (hepsi inherited), ama canonical form gereği yazılır.
//   Base'in copy constructor'ı zincirle çağrılır.
// ─────────────────────────────────────────────────────────────────────────────
ScavTrap::ScavTrap(ScavTrap const & src)
    : ClapTrap(src)  // base'in copy constructor'ını çağır
{
    std::cout << "[ScavTrap] Copy constructor called for " << src._name << std::endl;
    *this = src;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs); // base'in operator='ını explicit çağır
    return *this;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Destructor sırası (Destructor chaining) — TERS SIRADA!
//   Constructor: ClapTrap → ScavTrap
//   Destructor:  ScavTrap → ClapTrap  (otomatik, zincir tersine döner)
// ─────────────────────────────────────────────────────────────────────────────
ScavTrap::~ScavTrap()
{
    // ClapTrap destructor'ı bu bittikten sonra OTOMATİK çağrılır
    std::cout << "[ScavTrap] Destructor called for " << _name << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Function overriding (Fonksiyon ezme)
//   ScavTrap kendi attack() versiyonunu tanımlar.
//   ClapTrap::attack() hâlâ var ama ScavTrap nesnesi için bu çalışır.
//   Not: C++03'te virtual olmadan bu sadece NAME HIDING'dir, polimorfizm değil.
// ─────────────────────────────────────────────────────────────────────────────
void    ScavTrap::attack(std::string const & target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "[ScavTrap] " << _name
                  << " can't attack! No energy or HP left." << std::endl;
        return;
    }
    _energyPoints--;
    // Mesaj farklı: "savagely" → ScavTrap'in kendine has saldırısı
    std::cout << "[ScavTrap] " << _name
              << " attacks " << target
              << " savagely, causing " << _attackDamage
              << " points of damage!" << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Derived class'a özgü yeni fonksiyon
//   ClapTrap'te yoktur. Sadece ScavTrap nesneleri çağırabilir.
// ─────────────────────────────────────────────────────────────────────────────
void    ScavTrap::guardGate()
{
    if (_hitPoints <= 0)
    {
        std::cout << "[ScavTrap] " << _name
                  << " is dead and can't guard!" << std::endl;
        return;
    }
    std::cout << "[ScavTrap] " << _name
              << " is now in Gate keeper mode!" << std::endl;
}
