#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"

void printSeparator(std::string message) {
	std::cout << "---------------------" << message << "---------------------" << std::endl;
}

int main(void) {
  // test ShrubberyCreationForm
    printSeparator("test ShrubberyCreationForm");
    {
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        b.signForm(a);
        a.execute(b);
    }
    {
        printSeparator("exception form not signed");
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 1);
        try {
            a.execute(b);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        printSeparator("exception grade is too low");
        ShrubberyCreationForm a;
        Bureaucrat b = Bureaucrat("b", 138);
        try {
            b.signForm(a);
            a.execute(b);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
  // test RobotomyRequestForm
	printSeparator("test RobotomyRequestForm");
	{
		RobotomyRequestForm a;
		Bureaucrat b = Bureaucrat("b", 1);
		try {
			b.signForm(a);
			a.execute(b);
		} catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printSeparator("exception form not signed");
		RobotomyRequestForm a;
		Bureaucrat b = Bureaucrat("b", 1);
		try {
			a.execute(b);
		} catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
	{
		printSeparator("exception grade is too low");
		RobotomyRequestForm a;
		Bureaucrat b = Bureaucrat("b", 46);
		try {
			b.signForm(a);
			a.execute(b);
		} catch(const std::exception & e) {
			std::cerr << e.what() << std::endl;
		}
	}
  // test PresidentialPardonForm
}
