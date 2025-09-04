#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.h"
#include <fstream>

class ShrubberyCreationForm : public AForm {
public:
  ShrubberyCreationForm();
  explicit ShrubberyCreationForm(const std::string &target);
  ShrubberyCreationForm(const ShrubberyCreationForm &form);
  ShrubberyCreationForm &
  operator=(const ShrubberyCreationForm &form);
  ~ShrubberyCreationForm();
  const std::string &getTarget() const;
  void doExecute() const;

private:
  static const int kDefaultGradeSign = 145;
  static const int kDefaultGradeExec = 137;
  const std::string target_;
};

#endif
