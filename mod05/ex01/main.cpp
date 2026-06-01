#include "Bureaucrat.hpp"
#include "AForm.hpp"

// ex01'de concrete form yok; AForm'u test icin minimal bir stub ile test ederiz
class TestForm : public AForm
{
public:
    TestForm(const std::string& name, int s, int e) : AForm(name, s, e) {}
    TestForm(const TestForm& o) : AForm(o) {}
    ~TestForm() {}
    void executeAction() const { std::cout << "TestForm executed!" << std::endl; }
private:
    TestForm();
};

int main()
{
    // Basarili imzalama
    try {
        Bureaucrat alice("Alice", 10);
        TestForm   f("TaxForm", 20, 50);
        std::cout << f << std::endl;
        alice.signForm(f);
        std::cout << f << std::endl;
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    std::cout << "---" << std::endl;

    // Yetersiz grade
    try {
        Bureaucrat bob("Bob", 80);
        TestForm   f("VacationForm", 30, 50);
        bob.signForm(f);
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    std::cout << "---" << std::endl;

    // Gecersiz form grade
    try {
        TestForm f("BadForm", 0, 50);
    } catch (std::exception& e) { std::cerr << "Form creation: " << e.what() << std::endl; }

    return 0;
}
