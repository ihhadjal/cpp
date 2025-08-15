#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
    private:
    const std::string _name;
    bool              _isSigned;
    const int         _gradeRequiredSign;
    const int         _gradeRequiredExec;

    public:
    Form();
    Form(const Form &src);
    Form(const std::string name, const int gradetosign, const int gradetoexec);
    ~Form() throw();
    Form &operator=(const Form &rhs);

    std::string getName()const;
    bool        getSigned()const;
    int         getGradeSign()const;
    int         getGradeExec()const;

    class GradeTooLowException : public std::exception
    {
        private:
        const char * _msg;

        public:
        GradeTooLowException(const char *msg);
        const char *what() const throw();
    };
    class GradeTooHighException : public std::exception
    {
        private:
        const char * _msg;

        public:
        GradeTooHighException(const char *msg);
        const char *what() const throw();
    };
    void beSigned(Bureaucrat employee);

};

std::ostream &operator<<(std::ostream &o, const Form &i);
#endif