#include "ClapTrap.hpp"

// ─────────────────────────────────────────────────────────────────────────────
// KAZANIM: Nesne yaşam döngüsünü gözlemlemek
//   main() biterken scope'tan çıkan nesnelerin destructor'ları
//   LIFO sırasıyla (son giren ilk çıkar) otomatik çağrılır.
// ─────────────────────────────────────────────────────────────────────────────

int main()
{
    std::cout << "=== ClapTrap Testi ===" << std::endl;

    ClapTrap cl("Clappy"); // parametreli constructor çağrılır

    cl.attack("Skag");     // 1 enerji harcar
    cl.takeDamage(5);      // 5 HP kaybeder
    cl.beRepaired(3);      // 1 enerji harcar, 3 HP kazanır

    // ── Copy constructor testi ──
    std::cout << "\n--- Copy Constructor ---" << std::endl;
    ClapTrap cl2(cl);      // cl'nin kopyası oluşturulur
    cl2.attack("Bullymong");

    // ── Assignment operator testi ──
    std::cout << "\n--- Assignment Operator ---" << std::endl;
    ClapTrap cl3;          // default constructor
    cl3 = cl;              // operator= çağrılır
    cl3.takeDamage(2);

    std::cout << "\n=== main() bitiyor, destructor'lar LIFO sırayla çalışacak ===" << std::endl;
    // cl3 → cl2 → cl sırasıyla destroy edilir
    return 0;
}
