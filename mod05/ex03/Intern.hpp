#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
    Intern();
    Intern(const Intern& other);
    Intern& operator=(const Intern& other);
    ~Intern();

    AForm*  makeForm(const std::string& name, const std::string& target) const;

private:
    // Fonksiyon pointer tablosu icin static uretici metodlar
    static AForm* _makeShrubbery(const std::string& t);
    static AForm* _makeRobotomy (const std::string& t);
    static AForm* _makePardon   (const std::string& t);
};

#endif
