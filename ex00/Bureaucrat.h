#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  ~Bureaucrat();
  Bureaucrat(const std::string &name, int grade);
  const std::string &getName() const;
  int getGrade() const;
  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
  void IncrementGrade();
  void DecrementGrade();
  static const int kMaxGrade = 1;
  static const int kMinGrade = 150;

private:
  const std::string name_;
  int grade_;
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif
