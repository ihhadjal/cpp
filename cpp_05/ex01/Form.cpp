#include "Form.hpp"

Form::Form() : _isSigned(false), _gradeRequiredSign(0), _gradeRequiredExec(0){
    std::cout << "Form default constructor called\n";
}

Form::Form(const Form &src): _isSigned(false), _gradeRequiredSign(0), _gradeRequiredExec(0){
    *this = src;

    std::cout << "Form copy constructor called\n";
}

Form::Form(const int gradetosign, const int gradetoexec) 
    : _isSigned(false), _gradeRequiredSign(gradetosign), _gradeRequiredExec(gradetoexec){
    std::cout << "Form constructor called\n";
}

Form::~Form() throw(){
    std::cout << "Form destructor called";
}

Form &Form::operator=(const Form &rhs){
    this->_isSigned = rhs._isSigned;

    return *this;
}

std::string Form::getName()const{
    return _name;
}

bool Form::getSigned(){
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
