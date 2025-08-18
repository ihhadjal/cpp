#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
  private:
	std::string _target;

  public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm(const std::string target);
	virtual ~ShrubberyCreationForm() throw();
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	std::string getTarget() const;
	virtual void execute(Bureaucrat const &executor) const;
};

#endif
