#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
    std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm parametric constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    std::cout << "ShrubberyCreationForm copy assignment operator called\n";
    if (this != &other) {
        AForm::operator=(other); // base class assignment
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    // önce base class kontrolleri: imzalı mı? grade yeterli mi?
    checkExecute(executor);

    // dosya oluştur: <target>_shrubbery
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file.is_open())
        throw std::runtime_error("Could not open file");

    // ASCII ağaçlar yaz
    file << "        *        \n";
    file << "       ***       \n";
    file << "      *****      \n";
    file << "     *******     \n";
    file << "    *********    \n";
    file << "   ***********   \n";
    file << "       |||       \n";
    file << "       |||       \n";
    file << "                 \n";
    file << "    *            \n";
    file << "   ***     *     \n";
    file << "  *****   ***    \n";
    file << " ******* *****   \n";
    file << "    |||   |||    \n";
    file.close();
}
