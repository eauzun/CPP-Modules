#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat
{
public:
    class GradeTooHighException : public std::exception { public: const char* what() const throw(); };
    class GradeTooLowException  : public std::exception { public: const char* what() const throw(); };

    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    const std::string&  getName()  const;
    int                 getGrade() const;
    void                incrementGrade();
    void                decrementGrade();
    void                signForm(AForm& form);

private:
    const std::string _name;
    int               _grade;
    Bureaucrat();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
