#ifndef AFORM_HPP
# define AFORM_HPP

# include <exception>
# include <iostream>
# include <stdlib.h>

class	Bureaucrat;

class AForm
{
  private:
	const std::string _name;
	bool _isSigned;
	const int _gradeRequiredSign;
	const int _gradeRequiredExec;

  public:
	AForm();
	AForm(const AForm &src);
	AForm(const std::string name, const int gradetosign, const int gradetoexec);
	virtual ~AForm() throw();
	AForm &operator=(const AForm &rhs);

	std::string getName() const;
	bool getSigned() const;
	int getGradeSign() const;
	int getGradeExec() const;

	class GradeTooLowException : public std::exception
	{
		private:
		const char *_msg;

		public:
		GradeTooLowException(const char *msg);
		const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		private:
		const char *_msg;

		public:
		GradeTooHighException(const char *msg);
		const char *what() const throw();
	};
	virtual void beSigned(Bureaucrat &employee);
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream &operator<<(std::ostream &o, const AForm &i);
#endif