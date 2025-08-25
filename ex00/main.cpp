#include <iostream>
#include "Bureaucrat.h"

int main(void) {
	Bureaucrat a;
	try {
		std::cout << a.getGrade() << std::endl;
		a.DecrementGrade();
		std::cout << a.getGrade() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Bureaucrat b;
	try {
		std::cout << b.getGrade() << std::endl;
		for (int i = 0; i < Bureaucrat::kMinGrade; i++) {
			// std::cout << b.getGrade() << std::endl;
			b.IncrementGrade();
		}
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		Bureaucrat c = Bureaucrat("c", -1);
		std::cout << c.getGrade() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
