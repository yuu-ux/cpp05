#include "PresidentialPardonForm.h"
#include "Bureaucrat.h"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", kDefaultGradeSign, kDefaultGradeExec),
      target_("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", kDefaultGradeSign, kDefaultGradeExec),
      target_(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &form)
    : AForm(form), target_(form.target_) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
  AForm::operator=(form);
  return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}

const std::string &PresidentialPardonForm::getTarget() const { return target_; }

void PresidentialPardonForm::doExecute() const {
  std::cout << target_ << " has been pardoned by Zaphod Beeblebrox."
            << std::endl;
}
