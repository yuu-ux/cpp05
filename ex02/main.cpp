#include "Bureaucrat.h"
#include "AForm.h"

int main(void) {
  // test ShrubberyCreationForm
  // test RobotomyRequestForm
  // test PresidentialPardonForm
  std::cout << "----------------form << operator----------------" << std::endl;
  try {
    Form a = Form("a", 1, 1);
    std::cout << a << std::endl;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
