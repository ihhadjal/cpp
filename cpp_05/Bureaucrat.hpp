#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat
{
    private:
    const std::string _name;
    int               _grade;
    
    public:
    Bureaucrat();
    Bureaucrat(const Bureaucrat &src);
    Bureaucrat(const std::string name, int grade);
    virtual ~Bureaucrat() throw();
    Bureaucrat &operator=(const Bureaucrat &rhs);
    
    std::string getName()const;
    int         getGrade();
    void        incrementGrade(int points);
    void        decrementGrade(int points);

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
};

#endif