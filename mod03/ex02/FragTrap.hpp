#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Aynı base'den farklı derived class üretmek
//   ScavTrap ve FragTrap ikisi de ClapTrap'ten türer.
//   Her biri farklı stats ve farklı özel yeteneğe sahiptir.
//   Bu, inheritance ile kod tekrarını nasıl önlediğimizi gösterir:
//   attack(), takeDamage(), beRepaired() her ikisinde de tekrar yazılmaz.
// ─────────────────────────────────────────────────────────────────────────────

class FragTrap : public ClapTrap
{
public:
    // ── Canonical Form ────────────────────────────────────────────────────
    FragTrap();
    FragTrap(std::string const & name);
    FragTrap(FragTrap const & src);
    FragTrap & operator=(FragTrap const & rhs);
    ~FragTrap();

    // ── ScavTrap'te de attack() override edilmişti ────────────────────────
    // FragTrap da override eder — ama kendi mesajıyla
    void    attack(std::string const & target);

    // ── FragTrap'e özgü yetenek ───────────────────────────────────────────
    void    highFivesGuys(void);
};

#endif
