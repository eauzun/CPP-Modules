#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern&) {}
Intern& Intern::operator=(const Intern&) { return *this; }
Intern::~Intern() {}

AForm* Intern::_makeShrubbery(const std::string& t) { return new ShrubberyCreationForm(t); }
AForm* Intern::_makeRobotomy (const std::string& t) { return new RobotomyRequestForm(t);   }
AForm* Intern::_makePardon   (const std::string& t) { return new PresidentialPardonForm(t);}

AForm* Intern::makeForm(const std::string& name, const std::string& target) const
{
    // Tablo tabanli factory: if-else zinciri yok, kolayca genisletilebilir
    static const std::string keys[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    static AForm* (*ctors[3])(const std::string&) = {
        &Intern::_makeShrubbery,
        &Intern::_makeRobotomy,
        &Intern::_makePardon
    };

    for (int i = 0; i < 3; ++i) {
        if (name == keys[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return ctors[i](target);
        }
    }

    std::cerr << "Intern: unknown form \"" << name << "\"" << std::endl;
    return NULL;
}
