#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{
    private:
        // const olduğu için constructor'da initialization list zorunlu
        const std::string _name;
        int _grade; // 1 (en yüksek) → 150 (en düşük)

    public:
        // ── OCF ──────────────────────────────────────────────
        Bureaucrat();                                    // default constructor
        Bureaucrat(const std::string& name, int grade); // parametreli constructor
        Bureaucrat(const Bureaucrat& other);             // copy constructor
        Bureaucrat& operator=(const Bureaucrat& other); // copy assignment
        ~Bureaucrat();                                   // destructor

        // ── Getters ──────────────────────────────────────────
        const std::string& getName()  const;
        int                getGrade() const;

        // ── Grade işlemleri ──────────────────────────────────
        // increment → grade sayısını AZALTIR (1'e yaklaşır = yükselir)
        void incrementGrade();
        // decrement → grade sayısını ARTIRIR (150'ye yaklaşır = düşer)
        void decrementGrade();

        // ── Nested exception sınıfları ───────────────────────
        // subject: exception sınıfları OCF'ye uymak zorunda değil
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

// insertion operator overload (sınıf dışında tanımlanır)
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif