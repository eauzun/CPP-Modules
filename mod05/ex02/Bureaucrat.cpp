#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ── OCF ──────────────────────────────────────────────────────────────────────

Bureaucrat::Bureaucrat() : _name("default"), _grade(75) {
    std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade) {
    std::cout << "Bureaucrat parametric constructor called\n";
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called\n";
    if (this != &other)
        _grade = other._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrat destructor called\n";
}

// ── Getters ──────────────────────────────────────────────────────────────────

const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const {
    return _grade;
}

// ── Grade işlemleri ──────────────────────────────────────────────────────────

void Bureaucrat::incrementGrade() {
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

// ── Exception what()'ları ─────────────────────────────────────────────────────

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (maximum is 150)";
}

// ── operator<< ───────────────────────────────────────────────────────────────

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

// ── Form işlemleri ───────────────────────────────────────────────────────────

void Bureaucrat::signForm(AForm& f) {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << "\n";
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << f.getName()
                  << " because " << e.what() << "\n";
    }
}

void Bureaucrat::executeForm(AForm const& f) {
    try {
        f.execute(*this);
        std::cout << _name << " executed " << f.getName() << "\n";
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn't execute " << f.getName()
                  << " because " << e.what() << "\n";
    }
}
