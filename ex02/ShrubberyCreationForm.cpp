#include "ShrubberyCreationForm.h"
#include "AForm.h"
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("", kDefaultGreadSign, kDefaultGreadExec){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberycreation) : AForm(shrubberycreation) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberycreation) {
	if (this != &shrubberycreation) {
		AForm::operator=(shrubberycreation);
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void doExecute(Bureaucrat const& executor) const {

}
