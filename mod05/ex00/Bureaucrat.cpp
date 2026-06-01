#include "Bureaucrat.hpp"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{ return "grade is too high (min is 1)"; }

const char* Bureaucrat::GradeTooLowException::what() const throw()
{ return "grade is too low (max is 150)"; }

Bureaucrat::Bureaucrat(const std::string& name, int grade)
    : _name(name), _grade(grade)
{
    if (_grade < 1)   throw GradeTooHighException();
    if (_grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& o) : _name(o._name), _grade(o._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& o)
{
    if (this != &o) _grade = o._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string& Bureaucrat::getName()  const { return _name; }
int                Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < 1)   throw GradeTooHighException();
    --_grade;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150) throw GradeTooLowException();
    ++_grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    return os << b.getName() << ", bureaucrat grade " << b.getGrade();
}
