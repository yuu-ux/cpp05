#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm()
    : name_("default"), isSigned_(false), gradeRequiredSign_(kDefaultGrade),
      gradeRequiredExecute_(kDefaultGrade) {}

AForm::AForm(const AForm &form)
    : name_(form.getName()), isSigned_(form.getSigned()),
      gradeRequiredSign_(form.getGradeRequiredSign()),
      gradeRequiredExecute_(form.getGradeRequiredExecute()) {}

AForm::AForm(const std::string &name, const int gradeRequiredSign,
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

AForm &AForm::operator=(const AForm &form) {
  if (this != &form) {
    this->isSigned_ = form.getSigned();
  }
  return *this;
}

AForm::~AForm() {}

const char *AForm::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw() {
    return "Form Not Signed";
}

void AForm::beSigned(const Bureaucrat &bureaucrat) {
  if (bureaucrat.getGrade() <= gradeRequiredSign_) {
    isSigned_ = true;
  } else {
    throw GradeTooLowException();
  }
}

const std::string &AForm::getName() const { return name_; }

bool AForm::getSigned() const { return isSigned_; }

int AForm::getGradeRequiredSign() const { return gradeRequiredSign_; }

int AForm::getGradeRequiredExecute() const {
  return gradeRequiredExecute_;
}

std::ostream &operator<<(std::ostream &os, const AForm &form) {
  os << "name: " << form.getName() << std::endl
     << "signed: " << form.getSigned() << std::endl
     << "gradeRequiresSign: " << form.getGradeRequiredSign() << std::endl
     << "gradeRequiredExecute: " << form.getGradeRequiredExecute() << std::endl;
  return os;
}

void AForm::execute(Bureaucrat const& executor) const {
	if (!getSigned())
		throw FormNotSignedException();
    if (executor.getGrade() > gradeRequiredExecute_) {
		throw GradeTooLowException();
	}
	doExecute();
}
