#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ── OCF ──────────────────────────────────────────────────────────────────────

AForm::AForm() : _name("default"), _isSigned(false), _gradeSign(1), _gradeExec(1) {
    std::cout << "AForm default constructor called\n";
}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
    : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    std::cout << "AForm parametric constructor called\n";
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
    std::cout << "AForm copy constructor called\n";
}

AForm& AForm::operator=(const AForm& other) {
    std::cout << "AForm copy assignment operator called\n";
    if (this != &other)
        _isSigned = other._isSigned; // const'lar değiştirilemez
    return *this;
}

AForm::~AForm() {
    std::cout << "AForm destructor called\n";
}

// ── Getters ──────────────────────────────────────────────────────────────────

const std::string& AForm::getName() const {
    return _name;
}

bool AForm::getIsSigned() const {
    return _isSigned;
}

int AForm::getGradeSign() const {
    return _gradeSign;
}

int AForm::getGradeExec() const {
    return _gradeExec;
}

// ── İmzalama ─────────────────────────────────────────────────────────────────

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// ── Execute kontrol ───────────────────────────────────────────────────────────
// concrete class'ların execute() başında çağırdığı yardımcı metod

void AForm::checkExecute(Bureaucrat const& executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw GradeTooLowException();
}

// ── Exception what()'ları ─────────────────────────────────────────────────────

const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade is too high! (minimum is 1)";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade is too low! (maximum is 150)";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// ── operator<< ───────────────────────────────────────────────────────────────

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form: "             << f.getName()
       << " | Signed: "        << (f.getIsSigned() ? "yes" : "no")
       << " | Grade to sign: " << f.getGradeSign()
       << " | Grade to exec: " << f.getGradeExec();
    return os;
}
