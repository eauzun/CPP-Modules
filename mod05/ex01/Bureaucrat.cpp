#include "Bureaucrat.hpp"


// ── OCF ──────────────────────────────────────────────────────────────────────

// Default constructor: geçerli bir grade ver (örn. 75 orta seviye)
Bureaucrat::Bureaucrat() : _name("default"), _grade(75) {
    std::cout << "Bureaucrat default constructor called\n";
}

// Parametreli constructor: grade geçerliliğini burada kontrol et
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    std::cout << "Bureaucrat parametric constructor called\n";
    // _name const olduğu için initialization list'te atandı, burada sadece grade kontrol
    if (_grade < 1)
        throw GradeTooHighException(); // 1'den yüksek olamaz
    if (_grade > 150)
        throw GradeTooLowException();  // 150'den düşük olamaz
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    std::cout << "Bureaucrat copy constructor called\n";
}

// Copy assignment: _name const olduğu için kopyalanamaz, sadece grade kopyalanır
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "Bureaucrat copy assignment operator called\n";
    if (this != &other)
        _grade = other._grade; // _name const, değiştiremeyiz
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
    // grade sayısı azalır → rütbe YUKARI çıkar
    if (_grade - 1 < 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    // grade sayısı artar → rütbe AŞAĞI iner
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    _grade++;
}

// ── Exception what() implementasyonları ──────────────────────────────────────

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high! (minimum is 1)";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low! (maximum is 150)";
}

// ── Operator<< ───────────────────────────────────────────────────────────────

// subject formatı: "<name>, bureaucrat grade <grade>."
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

//signform
void Bureaucrat::signForm(Form& f) {
    try {
        f.beSigned(*this); // this = bu bureaucrat
        std::cout << _name << " signed " << f.getName() << "\n";
    }
    catch (std::exception& e) {
        std::cout << _name << " couldn't sign " << f.getName()
                  << " because " << e.what() << "\n";
    }
}