#include "Bureaucrat.h"

Bureaucrat::Bureaucrat() : name_(""), grade_(Bureaucrat::kMinGrade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(grade) {
  if (grade_ > kMinGrade)
    throw GradeTooLowException();
  else if (grade_ < kMaxGrade)
    throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
    : name_(bureaucrat.getName()), grade_(bureaucrat.getGrade()) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
  if (this != &bureaucrat) {
    this->grade_ = bureaucrat.getGrade();
  }
  return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return name_; }

int Bureaucrat::getGrade() const { return grade_; }

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}

void Bureaucrat::IncrementGrade() {
  if (grade_ <= Bureaucrat::kMaxGrade) {
    throw GradeTooHighException();
  }
  grade_--;
}

void Bureaucrat::DecrementGrade() {
  if (grade_ >= Bureaucrat::kMinGrade) {
    throw GradeTooLowException();
  }
  grade_++;
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat) {
  os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade()
     << ".";
  return os;
}
