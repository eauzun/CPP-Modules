#include "Form.hpp"
#include "Bureaucrat.hpp"

// ── OCF ──────────────────────────────────────────────────────────────────────

Form::Form() : _name("default"), _isSigned(false), _gradeSign(1), _gradeExec(1) {
    std::cout << "Form default constructor called\n";
}

Form::Form(const std::string& name, int gradeSign, int gradeExec)
    : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    std::cout << "Form parametric constructor called\n";
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {
    std::cout << "Form copy constructor called\n";
}

Form& Form::operator=(const Form& other) {
    std::cout << "Form copy assignment operator called\n";
    if (this != &other)
        _isSigned = other._isSigned; // const'lar değiştirilemiyor
    return *this;
}

Form::~Form() {
    std::cout << "Form destructor called\n";
}

// ── Getters ──────────────────────────────────────────────────────────────────

const std::string& Form::getName() const {
    return _name;
}

bool Form::getIsSigned() const {
    return _isSigned;
}

int Form::getGradeSign() const {
    return _gradeSign;
}

int Form::getGradeExec() const {
    return _gradeExec;
}

// ── beSigned ─────────────────────────────────────────────────────────────────

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

// ── Exception what()'ları ─────────────────────────────────────────────────────

const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade is too high! (minimum is 1)";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade is too low! (maximum is 150)";
}

// ── operator<< ───────────────────────────────────────────────────────────────

std::ostream& operator<<(std::ostream& os, const Form& f) {
    os << "Form: "            << f.getName()
       << " | Signed: "       << (f.getIsSigned() ? "yes" : "no")
       << " | Grade to sign: "<< f.getGradeSign()
       << " | Grade to exec: "<< f.getGradeExec();
    return os;
}