#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _isSigned(false), _gradeRequiredSign(0), _gradeRequiredExec(0)
{
	std::cout << "AForm default constructor called\n";
}

AForm::AForm(const AForm &src) : _isSigned(false), _gradeRequiredSign(0),
	_gradeRequiredExec(0)
{
	*this = src;
	std::cout << "AForm copy constructor called\n";
}

AForm::AForm(const std::string name, const int gradetosign,
	const int gradetoexec) : _name(name), _isSigned(false),
	_gradeRequiredSign(gradetosign), _gradeRequiredExec(gradetoexec)
{
	if (gradetosign < 1 || gradetoexec < 1)
		throw AForm::GradeTooHighException("Grade too high");
	if (gradetosign > 150 || gradetoexec > 150)
		throw AForm::GradeTooLowException("Grade too low");
	std::cout << "AForm constructor called\n";
}

AForm::~AForm() throw()
{
	std::cout << "AForm destructor called\n";
}

AForm &AForm::operator=(const AForm &rhs)
{
	this->_isSigned = rhs._isSigned;
	return (*this);
}

std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeSign() const
{
	return (this->_gradeRequiredSign);
}

int AForm::getGradeExec() const
{
	return (this->_gradeRequiredExec);
}

AForm::GradeTooLowException::GradeTooLowException(const char *msg) : _msg(msg)
{
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return (_msg);
}

AForm::GradeTooHighException::GradeTooHighException(const char *msg) : _msg(msg)
{
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return (_msg);
}

std::ostream &operator<<(std::ostream &o, const AForm &i)
{
	o << i.getName() << " form sign grade: " << i.getGradeSign() << " execution grade: " << i.getGradeExec() << " signature status: " << i.getSigned() << '\n';
	return (o);
}

void AForm::beSigned(Bureaucrat &employee)
{
	if (employee.getGrade() > this->getGradeSign())
		throw AForm::GradeTooLowException("Bureaucrat grade too low to sign");
	this->_isSigned = true;
}