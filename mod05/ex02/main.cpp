#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(42); // sabit seed, tutarli output icin

    std::cout << "=== ShrubberyCreationForm ===" << std::endl;
    try {
        Bureaucrat            b("Alice", 137);
        ShrubberyCreationForm f("garden");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    std::cout << "\n=== RobotomyRequestForm ===" << std::endl;
    try {
        Bureaucrat          b("Bob", 45);
        RobotomyRequestForm f("Bender");
        b.signForm(f);
        b.executeForm(f);
        b.executeForm(f);
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    std::cout << "\n=== PresidentialPardonForm ===" << std::endl;
    try {
        Bureaucrat             b("Charlie", 5);
        PresidentialPardonForm f("Ford Prefect");
        b.signForm(f);
        b.executeForm(f);
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    std::cout << "\n=== Imzasiz form ===" << std::endl;
    try {
        Bureaucrat             b("Dave", 1);
        PresidentialPardonForm f("Arthur");
        b.executeForm(f);
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    std::cout << "\n=== Yetersiz execute grade ===" << std::endl;
    try {
        Bureaucrat             signer("Eve", 25);
        Bureaucrat             runner("Frank", 100);
        PresidentialPardonForm f("Marvin");
        signer.signForm(f);
        runner.executeForm(f);
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    return 0;
}
