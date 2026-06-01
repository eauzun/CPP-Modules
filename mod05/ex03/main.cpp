#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
    std::srand(42);

    Intern intern;
    AForm* form;

    std::cout << "=== shrubbery creation ===" << std::endl;
    form = intern.makeForm("shrubbery creation", "garden");
    if (form) {
        Bureaucrat b("Alice", 137);
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    }

    std::cout << "\n=== robotomy request ===" << std::endl;
    form = intern.makeForm("robotomy request", "Bender");
    if (form) {
        Bureaucrat b("Bob", 45);
        b.signForm(*form);
        b.executeForm(*form);
        b.executeForm(*form);
        delete form;
    }

    std::cout << "\n=== presidential pardon ===" << std::endl;
    form = intern.makeForm("presidential pardon", "Ford Prefect");
    if (form) {
        Bureaucrat b("Charlie", 5);
        b.signForm(*form);
        b.executeForm(*form);
        delete form;
    }

    std::cout << "\n=== unknown form ===" << std::endl;
    form = intern.makeForm("coffee request", "Dave");
    if (form) delete form;

    return 0;
}
