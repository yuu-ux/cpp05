#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include "Bureaucrat.h"
#include <fstream>

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& shrubberycreation);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm& shrubberycreation);
		~ShrubberyCreationForm();
		const std::string &getTarget() const;
		void doExecute(Bureaucrat const& executor) const;
	private:
		static const int kDefaultGreadSign = 145;
		static const int kDefaultGreadExec = 137;
		const std::string target_;
};

#endif
