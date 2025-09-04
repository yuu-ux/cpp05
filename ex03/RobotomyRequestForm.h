#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.h"

#include <cstdlib>
#include <ctime>
class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  explicit RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &form);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
  ~RobotomyRequestForm();
  const std::string &getTarget() const;
  void doExecute() const;

private:
  static const int kDefaultGradeSign = 72;
  static const int kDefaultGradeExec = 45;
  const std::string target_;
};
#endif
