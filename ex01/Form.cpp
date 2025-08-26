#include "Form.h"
#include "Bureaucrat.h"

Form::Form()
    : name_(""), isSigned_(false), gradeRequiredSign_(kDefaultGrade),
      gradeRequiredExecute_(kDefaultGrade) {}

Form::Form(const Form &form)
    : name_(form.getName()), isSigned_(form.getSigned()),
      gradeRequiredSign_(form.getGradeRequiredSign()),
      gradeRequiredExecute_(form.getGradeRequiredExecute()) {}

Form &Form::operator=(const Form &form) {
  if (this != &form) {
    this->isSigned_ = form.getSigned();
  }
  return *this;
}

Form::~Form() {}

const char *Form::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

void Form::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= gradeRequiredSign_) {
    isSigned_ = true;
  } else {
      throw GradeTooLowException();
  }
}

const std::string &Form::getName() const { return name_; }

bool Form::getSigned() const { return isSigned_; }

const int &Form::getGradeRequiredSign() const { return gradeRequiredSign_; }

const int &Form::getGradeRequiredExecute() const {
  return gradeRequiredExecute_;
}
