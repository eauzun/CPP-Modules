#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    // ── 1. Constructor zincirini karşılaştır ──────────────────────────────
    std::cout << "=== Nesneler yaratılıyor ===" << std::endl;
    ClapTrap cl("Clappy");   // sadece [ClapTrap] constructor
    ScavTrap sc("Scooter");  // [ClapTrap] → [ScavTrap] sırasıyla
    FragTrap fr("Fraggles"); // [ClapTrap] → [FragTrap] sırasıyla

    // ── 2. Her sınıfın kendi attack()'i çalışır ───────────────────────────
    std::cout << "\n=== Attack karşılaştırması ===" << std::endl;
    cl.attack("Skag");      // [ClapTrap] mesajı
    sc.attack("Bullymong"); // [ScavTrap] mesajı — "savagely"
    fr.attack("Rakk");      // [FragTrap] mesajı — "with precision"

    // ── 3. Inherited fonksiyonlar: hepsi ClapTrap'ten ────────────────────
    std::cout << "\n=== Inherited fonksiyonlar ===" << std::endl;
    sc.takeDamage(20);  // ScavTrap'te tanımlı değil, ClapTrap'teki çalışır
    fr.beRepaired(15);  // aynı şekilde inherited

    // ── 4. Her sınıfın özel yeteneği ─────────────────────────────────────
    std::cout << "\n=== Özel yetenekler ===" << std::endl;
    sc.guardGate();       // sadece ScavTrap'te var
    fr.highFivesGuys();   // sadece FragTrap'te var
    // cl.guardGate();    // COMPILE ERROR! ClapTrap'te bu fonksiyon yok

    // ── 5. Base pointer — name hiding'i gözlemle ─────────────────────────
    // virtual olmadığı için pointer tipi hangi fonksiyonun çalışacağını belirler
    std::cout << "\n=== Base pointer (name hiding) ===" << std::endl;
    ClapTrap * ptr_sc = &sc;
    ClapTrap * ptr_fr = &fr;
    ptr_sc->attack("test"); // [ClapTrap] attack çalışır! ScavTrap değil!
    ptr_fr->attack("test"); // [ClapTrap] attack çalışır! FragTrap değil!
    // Bu davranış cpp04'teki "virtual" ile değişecek — polimorfizm orada başlar.

    // ── 6. Destructor sırası ──────────────────────────────────────────────
    std::cout << "\n=== main() bitiyor — destructor'lar LIFO ===" << std::endl;
    // fr  → [FragTrap] dest → [ClapTrap] dest
    // sc  → [ScavTrap] dest → [ClapTrap] dest
    // cl  → [ClapTrap] dest
    return 0;
}
