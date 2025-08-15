#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShruberryCreationForm.hpp"

int	main(void)
{
	std::cout << "=== Testing Bureaucrat and AForm ===" << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 140);
		Bureaucrat midGrade("MidGrade", 50);
		Bureaucrat highGrade("HighGrade", 1);
		std::cout << lowGrade << std::endl;
		std::cout << midGrade << std::endl;
		std::cout << highGrade << std::endl;
		std::cout << "\n=== Testing ShrubberyCreationForm ===" << std::endl;
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;
		lowGrade.signForm(shrub); 
		lowGrade.executeForm(shrub); 
		midGrade.executeForm(shrub); 
		std::cout << "\n=== Testing RobotomyRequestForm ===" << std::endl;
		RobotomyRequestForm robot("Iron Man");
		std::cout << robot << std::endl;
		lowGrade.signForm(robot); 
		midGrade.signForm(robot); 
		midGrade.executeForm(robot);  
		highGrade.executeForm(robot);
		std::cout << "\n=== Testing PresidentialPardonForm ===" << std::endl;
		PresidentialPardonForm pardon("Super Villain");
		std::cout << pardon << std::endl;
		midGrade.signForm(pardon); 
		highGrade.signForm(pardon);
		highGrade.executeForm(pardon);
		std::cout << "\n=== Testing Multiple Robotomy Attempts ===" << std::endl;
		RobotomyRequestForm robot2("TestSubject");
		highGrade.signForm(robot2);
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Attempt " << (i + 1) << ": ";
			highGrade.executeForm(robot2);
		}
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	return (0);
}
