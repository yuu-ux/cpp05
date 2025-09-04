#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.h"

class PresidentialPardonForm : public AForm {
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& form);
		PresidentialPardonForm &operator=(const PresidentialPardonForm& form);
		~PresidentialPardonForm();
		const std::string &getTarget() const;
		void doExecute() const;
	private:
		static const int kDefaultGreadSign = 25;
		static const int kDefaultGreadExec = 5;
		const std::string target_;

};
#endif
