#include "Intern.hpp"

// ── OCF ──────────────────────────────────────────────────────────────────────
// Intern'in tutacak verisi yok, trivial implementasyon

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

// ── Static oluşturucu fonksiyonlar ───────────────────────────────────────────
// Her biri ilgili formu heap'te oluşturup döndürür
// (fonksiyon pointer array'de saklanacak)

AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPardon(const std::string& target) {
    return new PresidentialPardonForm(target);
}

// ── makeForm ─────────────────────────────────────────────────────────────────

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {

    // fonksiyon pointer array — if/else yok!
    // her entry: { "form adı", &oluşturucu fonksiyon }
    const FormEntry forms[] = {
        { "shrubbery creation",   &Intern::createShrubbery },
        { "robotomy request",     &Intern::createRobotomy  },
        { "presidential pardon",  &Intern::createPardon    }
    };

    // kaç form var?
    const int count = 3;

    // array'i dolaş, eşleşen ismi bul
    for (int i = 0; i < count; i++) {
        if (forms[i].name == formName) {
            std::cout << "Intern creates " << formName << "\n";
            return forms[i].create(target); // fonksiyon pointer çağrısı
        }
    }

    // hiçbiri eşleşmediyse hata ver
    std::cout << "Intern: unknown form name: " << formName << "\n";
    return NULL;
}
