#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.h"

#include <cstdlib>
#include <ctime>
class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &form);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
  ~RobotomyRequestForm();
  const std::string &getTarget() const;
  void doExecute() const;

private:
  static const int kDefaultGreadSign = 72;
  static const int kDefaultGreadExec = 45;
  const std::string target_;
};
#endif
