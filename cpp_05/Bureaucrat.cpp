#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){
    std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src){
    *this = src;

    std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade){
    std::cout << "Bureaucrat constructor called\n";
}
Bureaucrat::~Bureaucrat() throw(){
    std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs){
    this->_grade = rhs._grade;

    return *this;
}

std::string Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade()const{
    return this->_grade;
}

void    Bureaucrat::incrementGrade(int points){
    _grade -= points;
}

void    Bureaucrat::decrementGrade(int points){
    _grade += points;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) : _msg(msg)
{}

const char *Bureaucrat::GradeTooLowException::what()const throw()
{
    return _msg;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) : _msg(msg)
{}

const char *Bureaucrat::GradeTooHighException::what()const throw()
{
    return _msg;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &i)
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade() << "\n";
    
    return o;
}