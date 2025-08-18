#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45),
	_target("default")
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src),
	_target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequest",
	72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm() throw()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::GradeTooLowException("Form not signed");
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException("Bureaucrat grade too low to execute");

	std::cout << "* DRILLING NOISES *" << std::endl;

	srand(time(NULL));

	if (rand() % 2 == 0)
	{
		std::cout << this->_target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed on " << this->_target << std::endl;
	}
}
