#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon",
	25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src),
	_target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardon",
	25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm() throw()
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::GradeTooLowException("Form not signed");
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException("Bureaucrat grade too low to execute");

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
