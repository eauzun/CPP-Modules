#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
class Form; // forward declaration

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        // ── OCF ──────────────────────────────────────────────
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        // ── Getters ──────────────────────────────────────────
        const std::string& getName()  const;
        int                getGrade() const;

        // ── Grade işlemleri ──────────────────────────────────
        void incrementGrade();
        void decrementGrade();

        // ── Form işlemleri ───────────────────────────────────
        void signForm(Form& f); // ← yeni

        // ── Nested exceptions ─────────────────────────────────
        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif