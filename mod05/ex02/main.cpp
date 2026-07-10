#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "── Test 1: ShrubberyCreationForm ──\n";
    try {
        Bureaucrat alice("Alice", 130);
        ShrubberyCreationForm shrubbery("garden");
        alice.signForm(shrubbery);
        alice.executeForm(shrubbery); // dosya oluşturur: garden_shrubbery
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n── Test 2: RobotomyRequestForm ──\n";
    try {
        Bureaucrat bob("Bob", 40);
        RobotomyRequestForm robotomy("Bender");
        bob.signForm(robotomy);
        bob.executeForm(robotomy); // %50 başarılı
        bob.executeForm(robotomy); // bir kez daha dene
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n── Test 3: PresidentialPardonForm ──\n";
    try {
        Bureaucrat zaphod("Zaphod", 4);
        PresidentialPardonForm pardon("Ford");
        zaphod.signForm(pardon);
        zaphod.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n── Test 4: İmzasız form execute ──\n";
    try {
        Bureaucrat carol("Carol", 1);
        PresidentialPardonForm pardon("Arthur");
        carol.executeForm(pardon); // imzalanmadı → hata
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n── Test 5: Grade yetersiz execute ──\n";
    try {
        Bureaucrat lowly("Lowly", 150);
        PresidentialPardonForm pardon("Trillian");
        // imzalamak için grade 25 lazım, 150 yetersiz
        lowly.signForm(pardon);
        lowly.executeForm(pardon);
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}
