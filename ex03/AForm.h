#ifndef AFORM_H
#define AFORM_H

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
public:
  // constructor, destructor
  AForm();
  AForm(const AForm &AForm);
  AForm &operator=(const AForm &AForm);
  virtual ~AForm();
  AForm(const std::string &name, const int gradeRequiredSign,
        const int gradeRequireExecute);

  // getter
  const std::string &getName() const;
  bool getSigned() const;
  int getGradeRequiredSign() const;
  int getGradeRequiredExecute() const;

  // exception class
  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
  class FormNotSignedException : public std::exception {
  public:
    virtual const char *what() const throw();
  };

  // func
  void beSigned(const Bureaucrat &bureaucrat);
  void execute(Bureaucrat const &executor) const;
  virtual void doExecute() const = 0;

private:
  const std::string name_;
  bool isSigned_;
  const int gradeRequiredSign_;
  const int gradeRequiredExecute_;
  static const int kDefaultGrade = 1;
};

std::ostream &operator<<(std::ostream &os, const AForm &form);

#endif
