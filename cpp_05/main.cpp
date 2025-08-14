#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat iheb("iheb", 160);
    Bureaucrat::GradeTooLowException iheb2("Error: the grade is too low\n");
    Bureaucrat::GradeTooHighException iheb3("Error: the grade is too high\n");
    try
    {
        if (iheb.getGrade() < 1)
            throw iheb3;
        else if (iheb.getGrade() > 150)
            throw iheb2;
    }
    catch (const std::exception  &e)
    {
        std::cout << e.what();
    }
}