#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
  private:
	std::string _target;

  public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm(const std::string target);
	virtual ~RobotomyRequestForm() throw();
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	std::string getTarget() const;
	virtual void execute(Bureaucrat const &executor) const;
};

#endif
