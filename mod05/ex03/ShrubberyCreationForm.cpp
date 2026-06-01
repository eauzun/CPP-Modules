#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
    : AForm(o), _target(o._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o)
{
    if (this != &o) { AForm::operator=(o); _target = o._target; }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const
{
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Cannot open file");
    file << "       _-_"        << std::endl
         << "    /~~   ~~\\"    << std::endl
         << " /~~         ~~\\" << std::endl
         << "{               }" << std::endl
         << " \\  _-     -_  /" << std::endl
         << "   ~  \\\\ //  ~"  << std::endl
         << "      // \\\\"     << std::endl;
    file.close();
    std::cout << "[Shrubbery] Created " << _target << "_shrubbery" << std::endl;
}
