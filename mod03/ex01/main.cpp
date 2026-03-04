#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== ScavTrap Testi ===" << std::endl;

    // ── Constructor zincirini izle ────────────────────────────────────────
    // Çıktıda önce [ClapTrap] sonra [ScavTrap] görürsün
    ScavTrap sc("Scooter");

    sc.attack("Bullymong");   // ScavTrap::attack() çalışır (override)
    sc.takeDamage(30);        // inherited: ClapTrap::takeDamage()
    sc.beRepaired(10);        // inherited: ClapTrap::beRepaired()
    sc.guardGate();           // ScavTrap'e özgü

    // ── Name hiding vs polymorphism farkını göster ────────────────────────
    // ClapTrap pointer'ı ScavTrap'e işaret ediyor
    // virtual olmadığı için ClapTrap::attack() çalışır (dikkat!)
    std::cout << "\n--- Name hiding demo (virtual olmadan) ---" << std::endl;
    ClapTrap * ptr = &sc;
    ptr->attack("Skag"); // ClapTrap::attack() çağrılır! ScavTrap::attack() değil!
                         // Bu farkı görmek için çıktıdaki [ClapTrap] tagına bak.

    // ── Destructor zincirini izle ─────────────────────────────────────────
    std::cout << "\n=== main() bitiyor ===" << std::endl;
    // Önce [ScavTrap] destructor, sonra [ClapTrap] destructor
    return 0;
}
