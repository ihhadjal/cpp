#include "Intern.hpp"

Intern::Intern()
{
    std::cout << "Intern constructor called\n";
}

Intern::Intern(const Intern &src)
{
    *this = src;

    std::cout << "Intern copy constructor called\n";
}

Intern::~Intern() throw()
{
    std::cout << "Intern destructor called\n";
}

Intern &Intern::operator=(const Intern &rhs)
{
    (void)rhs;
    
    //intern has no variables to copy

    return *this;
}

AForm *Intern::createPresidentialForm(const std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm *Intern::createShruberryForm(const std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomyForm(const std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
    typedef AForm *(Intern::*type)(const std::string target);

    type formType[3] = {&Intern::createRobotomyForm, &Intern::createPresidentialForm, &Intern::createShruberryForm};
    std::string names[3] = {"robotomy request", "presidential pardon request", "shruberry request"};

    for (int i = 0; i < 3; i++)
    {
        if (names[i] == formName)
        {
            std::cout << "Intern creates " << formName << std::endl;
            return (this->*formType[i])(target);
        }
    }
    std::cout << "Intern cannot create " << formName << " because it does not exist\n";
    return NULL;
}
