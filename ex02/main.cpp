#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"

void printSeparator(std::string message) {
	std::cout << "---------------------" << message << "---------------------" << std::endl;
}

int main(void) {
  // test ShrubberyCreationForm
    printSeparator("test ShrubberyCreationForm");
    {
        printSeparator("OK");
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        b.signForm(a);
        a.execute(b);
    }
    {
        printSeparator("NG");
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        try {
            a.execute(b);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        printSeparator("NG");
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 138);
        try {
            b.signForm(a);
            a.execute(b);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    // std::cout << a.execute() << std::endl;
  // test RobotomyRequestForm
  // test PresidentialPardonForm
}
