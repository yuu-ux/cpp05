#include "RobotomyRequestForm.h"
#include "Bureaucrat.h"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", kDefaultGreadSign, kDefaultGreadExec), target_("default"){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form) : AForm(form) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& form) {
        AForm::operator=(form);
        return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}

const std::string &RobotomyRequestForm::getTarget() const {
        return target_;
}

void RobotomyRequestForm::doExecute() const {
	std::cout << "~~drilling noises~~" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand()%2) {
		std::cout << target_ << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Robotomy failed on " << target_ << std::endl;
	}
}
