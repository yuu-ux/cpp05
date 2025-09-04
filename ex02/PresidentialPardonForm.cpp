#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", kDefaultGreadSign, kDefaultGreadExec), target_("default") {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form) : AForm(form) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& form) {
	AForm::operator=(form);
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::doExecute() const {
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;;
}
