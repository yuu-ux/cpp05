#include "Intern.h"
#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

Intern::Intern() {}
Intern::Intern(const Intern& intern) {
	*this = intern;
}

Intern &Intern::operator=(const Intern& intern) {
	(void)intern;
	return *this;
}

Intern::~Intern() {}


AForm* Intern::makeForm(const std::string& name, const std::string& target) {
	AForm *(Intern::*makeFormFunctions[])(const std::string &) = {
		&Intern::makeShrubberyCreationForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makePresidentialPardonForm,
	};
	std::string formNames[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon",
	};

	for (int i = 0; i < 3; ++i) {
		if (name == formNames[i]) {
			std::cout << "Intern creates " << name << std::endl;
			return (this->*makeFormFunctions[i])(target);
		}
	}
	std::cout << "Intern can't create" << name << std::endl;
	return NULL;
}


AForm *Intern::makeShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}
