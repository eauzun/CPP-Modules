#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Inheritance (Kalıtım) — "is-a" ilişkisi
//   ScavTrap bir ClapTrap'tir. ClapTrap'in tüm public/protected
//   üyelerine ve fonksiyonlarına otomatik olarak sahip olur.
//   "public" keyword'ü: base'in erişim belirleyicileri aynen korunur.
// ─────────────────────────────────────────────────────────────────────────────

class ScavTrap : public ClapTrap  // public inheritance
{
public:
    // ── Canonical Form ────────────────────────────────────────────────────
    // Her constructor base class constructor'ını zincirle çağırmalı!
    ScavTrap();
    ScavTrap(std::string const & name);
    ScavTrap(ScavTrap const & src);
    ScavTrap & operator=(ScavTrap const & rhs);
    ~ScavTrap();

    // ── Override: aynı isimli fonksiyon base'dekinin önüne geçer ─────────
    // ClapTrap::attack() değil, ScavTrap::attack() çalışır
    void    attack(std::string const & target);

    // ── ScavTrap'e özgü yeni fonksiyon ───────────────────────────────────
    void    guardGate();
};

#endif
