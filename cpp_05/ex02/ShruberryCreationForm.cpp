#include "Bureaucrat.hpp"
#include "ShruberryCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145,
	137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src),
	_target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreation",
	145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm() throw()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw AForm::GradeTooLowException("Form not signed");
	if (executor.getGrade() > this->getGradeExec())
		throw AForm::GradeTooLowException("Bureaucrat grade too low to execute");

	std::string filename = this->_target + "_shrubbery";
	std::ofstream file(filename.c_str());

	if (!file.is_open())
		throw std::runtime_error("Could not create file");

	file << "       _-_\n";
	file << "    /~~   ~~\\\n";
	file << " /~~         ~~\\\n";
	file << "{               }\n";
	file << " \\  _-     -_  /\n";
	file << "   ~  \\\\ //  ~\n";
	file << "_- -   | | _- _\n";
	file << "  _ -  | |   -_\n";
	file << "      // \\\\\n";
	file.close();
}
