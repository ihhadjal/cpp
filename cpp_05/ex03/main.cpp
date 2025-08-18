#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
    Intern intern;

    AForm  *form;
    std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
    form = intern.makeForm("presidential pardon request", "iheb");
    
    std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
    form = intern.makeForm("robotomy request", "iheb");

    std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
    form = intern.makeForm("shruberry request", "iheb");

    std::cout << "\n=== Non Existing form ===" << std::endl;
    form = intern.makeForm("iheb", "Bender");
    delete form;
}
