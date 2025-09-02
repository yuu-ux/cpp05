#ifndef AFORM_H
#define AFORM_H

#include <iostream>

class Bureaucrat;

class AForm {
public:
  AForm();
  AForm(const AForm &AForm);
  AForm &operator=(const AForm &AForm);
  ~AForm();
  AForm(const std::string &name, const int gradeRequiredSign,
       const int gradeRequireExecute);
  const std::string &getName() const;
  bool getSigned() const;
  const int getGradeRequiredSign() const;
  const int getGradeRequiredExecute() const;
  void beSigned(const Bureaucrat &bureaucrat);
  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
  virtual void execute(Bureaucrat const& executor) const = 0;

private:
  const std::string name_;
  bool isSigned_;
  const int gradeRequiredSign_;
  const int gradeRequiredExecute_;
  static const int kDefaultGrade = 1;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
