#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm parametric constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm copy assignment operator called\n";
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called\n";
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    checkExecute(executor);

    // matkap sesi
    std::cout << "BZZZZZZZZZT DRRRRRRRR VRRRRRRM...\n";

    // %50 ihtimalle başarılı
    std::srand(std::time(0));
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully!\n";
    else
        std::cout << _target << " robotomy failed!\n";
}
