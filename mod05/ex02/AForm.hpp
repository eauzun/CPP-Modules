#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat; // forward declaration

class AForm
{
    private:
        const std::string _name;
        bool              _isSigned;
        const int         _gradeSign;
        const int         _gradeExec;

    public:
        // ── OCF ──────────────────────────────────────────────
        AForm();
        AForm(const std::string& name, int gradeSign, int gradeExec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm(); // virtual — miras alındığı için

        // ── Getters ──────────────────────────────────────────
        const std::string& getName()      const;
        bool               getIsSigned()  const;
        int                getGradeSign() const;
        int                getGradeExec() const;

        // ── İmzalama ─────────────────────────────────────────
        void beSigned(const Bureaucrat& b);

        // ── Execute ───────────────────────────────────────────
        // pure virtual → AForm abstract class oldu
        virtual void execute(Bureaucrat const& executor) const = 0;

        // base class'ta kontrol yapan yardımcı metod
        // concrete class'lar execute() içinde bunu çağırır
        void checkExecute(Bureaucrat const& executor) const;

        // ── Nested exceptions ─────────────────────────────────
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
