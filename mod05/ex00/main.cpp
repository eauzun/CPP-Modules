#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat alice("Alice", 42);
        std::cout << alice << std::endl;
        alice.incrementGrade();
        std::cout << "After increment: " << alice << std::endl;
        alice.decrementGrade();
        std::cout << "After decrement: " << alice << std::endl;
    } catch (std::exception& e) { std::cerr << e.what() << std::endl; }

    try { Bureaucrat bob("Bob", 0); }
    catch (std::exception& e) { std::cerr << "Bob: " << e.what() << std::endl; }

    try { Bureaucrat charlie("Charlie", 151); }
    catch (std::exception& e) { std::cerr << "Charlie: " << e.what() << std::endl; }

    try {
        Bureaucrat dave("Dave", 1);
        dave.incrementGrade();
    } catch (std::exception& e) { std::cerr << "Dave: " << e.what() << std::endl; }

    try {
        Bureaucrat eve("Eve", 150);
        eve.decrementGrade();
    } catch (std::exception& e) { std::cerr << "Eve: " << e.what() << std::endl; }

    return 0;
}
