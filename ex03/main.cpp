#include "AForm.h"
#include "Intern.h"

void printSeparator(std::string message) {
  std::cout << "---------------------" << message << "---------------------"
            << std::endl;
}

int main(void) {
  {
    printSeparator("test shrubbery");
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "Bender");
    std::cout << *rrf << std::endl;
  }
  std::cout << '\n';
  {
    printSeparator("test robotomy");
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    std::cout << *rrf << std::endl;
  }
  std::cout << '\n';
  {
    printSeparator("test presidential");
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("presidential pardon", "Bender");
    std::cout << *rrf << std::endl;
  }
  std::cout << '\n';
  {
    printSeparator("test invalid name");
    Intern someRandomIntern;
    AForm *rrf;
    rrf = someRandomIntern.makeForm("hoge", "Bender");
  }
}
