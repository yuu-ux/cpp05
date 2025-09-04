#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm {
public:
  PresidentialPardonForm();
  explicit PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &form);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &form);
  ~PresidentialPardonForm();
  const std::string &getTarget() const;
  void doExecute() const;

private:
  static const int kDefaultGradeSign = 25;
  static const int kDefaultGradeExec = 5;
  const std::string target_;
};
#endif
