#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
  protected:
	std::string _target;

  public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm(const std::string target);
	virtual ~PresidentialPardonForm() throw();
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	std::string getTarget() const;
	virtual void execute(Bureaucrat const &executor) const;
};

#endif
