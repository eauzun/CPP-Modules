#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeSign(1), _gradeExec(1) {}

AForm::AForm(const std::string& name, int gradeSign, int gradeExec)
    : _name(name), _isSigned(false), _gradeSign(gradeSign), _gradeExec(gradeExec) {
    if (_gradeSign < 1 || _gradeExec < 1)
        throw GradeTooHighException();
    if (_gradeSign > 150 || _gradeExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& other)
    : _name(other._name), _isSigned(other._isSigned),
      _gradeSign(other._gradeSign), _gradeExec(other._gradeExec) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        _isSigned = other._isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName()      const { return _name; }
bool               AForm::getIsSigned()  const { return _isSigned; }
int                AForm::getGradeSign() const { return _gradeSign; }
int                AForm::getGradeExec() const { return _gradeExec; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeSign)
        throw GradeTooLowException();
    _isSigned = true;
}

void AForm::checkExecute(Bureaucrat const& executor) const {
    if (!_isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > _gradeExec)
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what()   const throw() { return "Form grade is too high!"; }
const char* AForm::GradeTooLowException::what()    const throw() { return "Form grade is too low!"; }
const char* AForm::FormNotSignedException::what()  const throw() { return "Form is not signed!"; }

std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form: "             << f.getName()
       << " | Signed: "        << (f.getIsSigned() ? "yes" : "no")
       << " | Grade to sign: " << f.getGradeSign()
       << " | Grade to exec: " << f.getGradeExec();
    return os;
}
