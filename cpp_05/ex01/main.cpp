#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Form iheb(160, 10);
    Form::GradeTooHighException iheb2("Error: the grade is too high\n");
    Form::GradeTooLowException iheb3("Error: the grade is too low\n");

    try
    {
        if (iheb.getGradeExec() < 1 || iheb.getGradeSign() < 1)
            throw iheb2;
        else if (iheb.getGradeExec() > 150 || iheb.getGradeSign() > 150)
            throw iheb3;
    }
    catch(const std::exception &e)
    {
        std::cout << e.what();
        exit (1);
    }
    
}