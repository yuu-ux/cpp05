#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include <iostream>

class Bureaucrat {
public:
  Bureaucrat();
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  ~Bureaucrat();
  const std::string &getName() const;
  int getGrade() const;
  class GradeTooHighException : public std::exception {
    virtual const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
    virtual const char *what() const throw();
  };
  Bureaucrat operator++();
  void IncrementGrade();
  void DecrementGrade();

private:
  static const int kMaxGrade = 1;
  static const int kMinGrade = 150;
  const std::string name_;
  int grade_;
};

#endif
