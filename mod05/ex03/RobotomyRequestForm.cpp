#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
    : AForm(o), _target(o._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o)
{
    if (this != &o) { AForm::operator=(o); _target = o._target; }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const
{
    std::cout << "Bzzzzzzzzz... *drilling noises*" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " robotomized successfully!" << std::endl;
    else
        std::cout << _target << " robotomy failed." << std::endl;
}
