#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool              _isSigned;
        const int         _gradeSign;
        const int         _gradeExec;

    public:
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        const std::string& getName()      const;
        bool               getIsSigned()  const;
        int                getGradeSign() const;
        int                getGradeExec() const;

        void beSigned(const Bureaucrat& b);
        void checkExecute(Bureaucrat const& executor) const;

        virtual void execute(Bureaucrat const& executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                const char* what() const throw();
        };
        class GradeTooLowException : public std::exception {
            public:
                const char* what() const throw();
        };
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw();
        };
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
