#include "ShrubberyCreationForm.h"
#include "AForm.h"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", kDefaultGreadSign, kDefaultGreadExec), target_("default"){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberycreation) : AForm(shrubberycreation) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberycreation) {
	AForm::operator=(shrubberycreation);
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::doExecute(Bureaucrat const& executor) const {
	const std::string fileName = target_ + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (!file.is_open())
		throw std::runtime_error("can't open file");

	std::string shrubbery =
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\\n";
	file << shrubbery;
	file.close();
}
