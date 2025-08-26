#include "Form.h"
#include "Bureaucrat.h"

Form::Form()
    : name_(""), isSigned_(false), gradeRequiredSign_(kDefaultGrade),
      gradeRequiredExecute_(kDefaultGrade) {}

Form::Form(const Form &form)
    : name_(form.getName()), isSigned_(form.getSigned()),
      gradeRequiredSign_(form.getGradeRequiredSign()),
      gradeRequiredExecute_(form.getGradeRequiredExecute()) {}

Form::Form(const std::string &name, const int gradeRequiredSign,
           const int gradeRequiredExecute)
    : name_(name), isSigned_(false), gradeRequiredSign_(gradeRequiredSign),
      gradeRequiredExecute_(gradeRequiredExecute) {
  if (gradeRequiredExecute_ < Bureaucrat::kMaxGrade ||
      gradeRequiredSign_ < Bureaucrat::kMaxGrade) {
    throw GradeTooHighException();
  } else if (gradeRequiredExecute_ > Bureaucrat::kMinGrade ||
             gradeRequiredSign_ > Bureaucrat::kMinGrade) {
    throw GradeTooLowException();
  }
}

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

const int Form::getGradeRequiredSign() const { return gradeRequiredSign_; }

const int Form::getGradeRequiredExecute() const {
  return gradeRequiredExecute_;
}

std::ostream &operator<<(std::ostream &os, const Form &form) {
  os << "name: " << form.getName() << std::endl
     << "signed: " << form.getSigned() << std::endl
     << "gradeRequiresSign: " << form.getGradeRequiredSign() << std::endl
     << "gradeRequiredExecute: " << form.getGradeRequiredExecute() << std::endl;
  return os;
}
