#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "── Test 1: Normal imzalama ──\n";
    try {
        Bureaucrat alice("Alice", 30);
        Form       tax("TaxForm", 50, 100);
        std::cout << alice << "\n";
        std::cout << tax   << "\n";
        alice.signForm(tax); // grade 30 < 50 → imzalar
        std::cout << tax   << "\n";
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n── Test 2: Yetersiz grade ──\n";
    try {
        Bureaucrat bob("Bob", 100);
        Form       vip("VIPForm", 50, 100);
        bob.signForm(vip); // grade 100 > 50 → imzalayamaz
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n── Test 3: Geçersiz form grade ──\n";
    try {
        Form bad("BadForm", 0, 50); // GradeTooHighException
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    return 0;
}