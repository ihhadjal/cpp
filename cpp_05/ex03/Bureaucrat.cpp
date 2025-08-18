#include "AForm.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name)
{
	*this = src;
	std::cout << "Bureaucrat copy constructor called\n";
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high");
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException("Grade too low");
	this->_grade = grade;
	std::cout << "Bureaucrat constructor called\n";
}

Bureaucrat::~Bureaucrat() throw()
{
	std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->_grade = rhs._grade;
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade(int points)
{
	if (this->_grade - points < 1)
		throw Bureaucrat::GradeTooHighException("Grade too high");
	this->_grade -= points;
}

void Bureaucrat::decrementGrade(int points)
{
	if (this->_grade + points > 150)
		throw Bureaucrat::GradeTooLowException("Grade too low");
	this->_grade += points;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(const char *msg) : _msg(msg)
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_msg);
}

Bureaucrat::GradeTooHighException::GradeTooHighException(const char *msg) : _msg(msg)
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_msg);
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade() << ".";
	return (o);
}