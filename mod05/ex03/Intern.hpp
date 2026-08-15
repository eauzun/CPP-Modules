#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        // OCF — içinde tutacak veri yok, trivial
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);
        ~Intern();

        // Ana fonksiyon: form adı + target alır, AForm* döndürür
        AForm* makeForm(const std::string& formName, const std::string& target) const;

    private:
        // if/else yerine fonksiyon pointer array kullanıyoruz
        // Her entry: { "form adı", oluşturucu fonksiyon }
        struct FormEntry {
            std::string name;
            AForm*      (*create)(const std::string& target); // fonksiyon pointer
        };

        // 3 concrete form için static oluşturucu fonksiyonlar
        static AForm* createShrubbery(const std::string& target);
        static AForm* createRobotomy(const std::string& target);
        static AForm* createPardon(const std::string& target);
};

#endif
