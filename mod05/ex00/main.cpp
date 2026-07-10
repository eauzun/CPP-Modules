#include "Bureaucrat.hpp"

int main()
{
    std::cout << "── Test 1: Normal oluşturma ──\n";
    try {
        Bureaucrat alice("Alice", 42);
        std::cout << alice << "\n"; // operator<< testi
    }
    catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << "\n";
    }

    std::cout << "\n── Test 2: Grade çok yüksek (0) ──\n";
    try {
        Bureaucrat bad("Bad", 0); // GradeTooHighException bekliyoruz
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "\n── Test 3: Grade çok düşük (151) ──\n";
    try {
        Bureaucrat bad("Bad", 151); // GradeTooLowException bekliyoruz
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "\n── Test 4: increment/decrement sınır testi ──\n";
    try {
        Bureaucrat top("Top", 1);
        std::cout << top << "\n";
        top.incrementGrade(); // grade 1'den daha yüksek olamaz → exception
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    std::cout << "\n── Test 5: decrement sınır testi ──\n";
    try {
        Bureaucrat bot("Bot", 150);
        std::cout << bot << "\n";
        bot.decrementGrade(); // grade 150'den daha düşük olamaz → exception
    }
    catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << "\n";
    }

    return 0;
}