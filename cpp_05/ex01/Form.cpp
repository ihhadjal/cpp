#include "Form.hpp"
#include "Bureaucrat.hpp"
Form::Form() : _isSigned(false), _gradeRequiredSign(0), _gradeRequiredExec(0){
    std::cout << "Form default constructor called\n";
}

Form::Form(const Form &src): _isSigned(false), _gradeRequiredSign(0), _gradeRequiredExec(0){
    *this = src;

    std::cout << "Form copy constructor called\n";
}

Form::Form(const std::string name, const int gradetosign, const int gradetoexec) 
    :_name(name), _isSigned(false),
     _gradeRequiredSign(gradetosign),
     _gradeRequiredExec(gradetoexec)
{
    std::cout << "Form constructor called\n";
}

Form::~Form() throw(){
    std::cout << "Form destructor called\n";
}

Form &Form::operator=(const Form &rhs){
    this->_isSigned = rhs._isSigned;

    return *this;
}

std::string Form::getName()const{
    return _name;
}

bool Form::getSigned()const{
    return this->_isSigned;
}

int Form::getGradeSign()const{
    return this->_gradeRequiredSign;
}

int Form::getGradeExec()const{
    return this->_gradeRequiredExec;
}

Form::GradeTooLowException::GradeTooLowException(const char *msg) : _msg(msg)
{}

const char *Form::GradeTooLowException::what()const throw()
{
    return _msg;
}

Form::GradeTooHighException::GradeTooHighException(const char *msg) : _msg(msg)
{}

const char *Form::GradeTooHighException::what()const throw()
{
    return _msg;
}

std::ostream &operator<<(std::ostream &o, const Form &i)
{
    o << i.getName() << " form sign grade: " << i.getGradeSign() << " execution grade: " 
    << i.getGradeExec() << " signature status: " << i.getSigned() << '\n';
    
    return o;
}

void    Form::beSigned(Bureaucrat &employee)
{
    Form::GradeTooLowException exception("the Bureaucrat grade is too low\n");
    Form::GradeTooLowException exception1("the Bureaucrat grade is too high\n");
    try 
    {
        if (employee.getGrade() > this->getGradeExec() && employee.getGrade() > this->getGradeSign())
            throw exception;
    }
    catch(const std::exception &e)
    {
        std::cout << employee.getName() << " couldn't sign " << this->getName() 
            << " because " << e.what();
        exit (1);
    }
    this->_isSigned = true;
    std::cout << employee.getName() << " signed " << this->getName() << '\n';
}