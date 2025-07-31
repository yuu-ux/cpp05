#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat &operator=(const Bureaucrat& bureaucrat);
		~Bureaucrat();
		std::string getName();
		int getGrade();
	private:
		const std::string name_;
		int grade_;
};

#endif
