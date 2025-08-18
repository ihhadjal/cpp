#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

class Intern
{
    private:
    AForm *createPresidentialForm(const std::string target);
    AForm *createRobotomyForm(const std::string target);
    AForm *createShruberryForm(const std::string target);

    public:
    Intern();
    Intern(const Intern &src);
    virtual ~Intern() throw();
    Intern &operator=(const Intern &rhs);

    AForm *makeForm(const std::string formName, const std::string target);
};
#endif