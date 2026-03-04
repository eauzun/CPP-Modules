#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <string>
# include <iostream>

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Header guard (#ifndef / #define / #endif)
//   Aynı header'ın birden fazla kez include edilmesini önler.
//   C++03'te <string> ve <iostream> standart kütüphane başlıklarıdır.
// ─────────────────────────────────────────────────────────────────────────────

class ClapTrap
{
public:
    // ── Canonical Form (Orthodox Canonical Form) ──────────────────────────
    // 42'nin istediği 4 büyük: default constructor, copy constructor,
    // copy assignment operator, destructor. Bunlar olmadan sınıf eksik sayılır.
    ClapTrap();                                  // Default constructor
    ClapTrap(std::string const & name);          // Parametreli constructor
    ClapTrap(ClapTrap const & src);              // Copy constructor
    ClapTrap & operator=(ClapTrap const & rhs);  // Copy assignment operator
    ~ClapTrap();                                 // Destructor

    // ── Member functions ──────────────────────────────────────────────────
    void    attack(std::string const & target);
    void    takeDamage(unsigned int amount);
    void    beRepaired(unsigned int amount);

protected:
    // ── protected: türeyen sınıflar erişebilir, dışarıdan erişilemez ──────
    // Eğer private yapsaydık ScavTrap/FragTrap bu üyelere ulaşamazdı.
    std::string     _name;
    int             _hitPoints;
    int             _energyPoints;
    int             _attackDamage;
};

#endif
