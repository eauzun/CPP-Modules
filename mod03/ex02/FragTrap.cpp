#include "FragTrap.hpp"

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Her derived class kendi stats'ını tanımlar
//   FragTrap'in HP, enerji ve hasar değerleri ScavTrap'ten farklı.
//   Ama mekanizma (ClapTrap'ten inherit etme) aynı.
//
//   ClapTrap:  HP=10,  Energy=10, Damage=0
//   ScavTrap:  HP=100, Energy=50, Damage=20
//   FragTrap:  HP=100, Energy=100, Damage=30
// ─────────────────────────────────────────────────────────────────────────────

FragTrap::FragTrap()
    : ClapTrap()  // base önce init edilir
{
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "[FragTrap] Default constructor called for " << _name << std::endl;
}

FragTrap::FragTrap(std::string const & name)
    : ClapTrap(name)  // ismi base'e ilet
{
    _hitPoints    = 100;
    _energyPoints = 100;
    _attackDamage = 30;
    std::cout << "[FragTrap] Constructor called for " << _name << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Derived class'larda canonical form tutarlılığı
//   ScavTrap ile aynı pattern. Her derived class bunu tekrar eder.
//   Bu şablonu ezberlemek yerine mantığını anlamak önemli:
//   "Base'i init et, kendi ekstralarını ayarla."
// ─────────────────────────────────────────────────────────────────────────────
FragTrap::FragTrap(FragTrap const & src)
    : ClapTrap(src)
{
    std::cout << "[FragTrap] Copy constructor called for " << src._name << std::endl;
    *this = src;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
    if (this != &rhs)
        ClapTrap::operator=(rhs); // base'in assignment'ını çağır
    return *this;
}

// Destructor — bittikten sonra ClapTrap::~ClapTrap() otomatik çalışır
FragTrap::~FragTrap()
{
    std::cout << "[FragTrap] Destructor called for " << _name << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Aynı fonksiyon adı, farklı davranış
//   ScavTrap::attack() "savagely" der, FragTrap::attack() farklı mesaj verir.
//   Hangi nesne çağırıyorsa onun versiyonu çalışır.
//   (Compile-time binding — virtual olmadığı için runtime değil)
// ─────────────────────────────────────────────────────────────────────────────
void    FragTrap::attack(std::string const & target)
{
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << "[FragTrap] " << _name
                  << " can't attack! No energy or HP left." << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "[FragTrap] " << _name
              << " attacks " << target
              << " with precision, causing " << _attackDamage
              << " points of damage!" << std::endl;
}

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Her derived class kendi unique yeteneğine sahip olabilir
//   ScavTrap → guardGate()
//   FragTrap → highFivesGuys()
//   İkisini de ClapTrap pointer'ıyla çağıramazsın (virtual olmadan).
// ─────────────────────────────────────────────────────────────────────────────
void    FragTrap::highFivesGuys(void)
{
    if (_hitPoints <= 0)
    {
        std::cout << "[FragTrap] " << _name
                  << " is dead... no high fives today." << std::endl;
        return;
    }
    // Pozitif, neşeli bir istek — FragTrap'in kişiliği
    std::cout << "[FragTrap] " << _name
              << " requests a HIGH FIVE! :D" << std::endl;
}
