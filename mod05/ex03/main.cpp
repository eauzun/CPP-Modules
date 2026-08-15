#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    Intern someIntern;
    AForm* form;

    std::cout << "── Test 1: robotomy request ──\n";
    form = someIntern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat boss("Boss", 40);
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form; // heap'te oluşturuldu, sil!
    }

    std::cout << "\n── Test 2: shrubbery creation ──\n";
    form = someIntern.makeForm("shrubbery creation", "garden");
    if (form) {
        Bureaucrat gardener("Gardener", 130);
        gardener.signForm(*form);
        gardener.executeForm(*form);
        delete form;
    }

    std::cout << "\n── Test 3: presidential pardon ──\n";
    form = someIntern.makeForm("presidential pardon", "Zaphod");
    if (form) {
        Bureaucrat president("President", 4);
        president.signForm(*form);
        president.executeForm(*form);
        delete form;
    }

    std::cout << "\n── Test 4: bilinmeyen form ──\n";
    form = someIntern.makeForm("coffee request", "Bender");
    if (!form)
        std::cout << "No form created.\n";

    return 0;
}
