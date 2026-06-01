#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char* AForm::GradeTooHighException::what()  const throw() { return "form: grade too high"; }
const char* AForm::GradeTooLowException::what()   const throw() { return "form: grade too low"; }
const char* AForm::FormNotSignedException::what() const throw() { return "form: not signed"; }

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)     throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& o)
    : _name(o._name), _isSigned(o._isSigned),
      _gradeToSign(o._gradeToSign), _gradeToExecute(o._gradeToExecute) {}

AForm& AForm::operator=(const AForm& o)
{
    if (this != &o) _isSigned = o._isSigned;
    return *this;
}

AForm::~AForm() {}

const std::string& AForm::getName()           const { return _name; }
bool               AForm::getIsSigned()       const { return _isSigned; }
int                AForm::getGradeToSign()    const { return _gradeToSign; }
int                AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > _gradeToSign) throw GradeTooLowException();
    _isSigned = true;
}

void AForm::execute(const Bureaucrat& executor) const
{
    if (!_isSigned)                          throw FormNotSignedException();
    if (executor.getGrade() > _gradeToExecute) throw GradeTooLowException();
    executeAction();
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
    return os << "Form[" << f.getName()
              << "] signed=" << (f.getIsSigned() ? "yes" : "no")
              << " signGrade=" << f.getGradeToSign()
              << " execGrade=" << f.getGradeToExecute();
}
