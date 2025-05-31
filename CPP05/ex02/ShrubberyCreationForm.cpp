#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
	if (executor.getGrade() > this->getGradeToExec())
		throw GradeTooLowException("Your grade is not enough to execute in ShrubberyCreationForm");

	std::string fileName = _target + "_shrubbery";
	std::ofstream file(fileName);
	if (file.fail()) {
		std::cerr << "File openning failed." << std::endl;
		return ;
	}
	file << R"(
 
 
              _{\ _{\{\/}/}/}__
             {/{/\}{/{/\}(\}{/\} _
            {/{/\}{/{/\}(_)\}{/{/\}_
         {\{/(\}\}{/{/\}\}{/){/\}\}/\}
        {/{/(_)/}{\{/)\}{\(_){/}/}/}/}
       _{\{/{/{\{/{/(_)/}/}/}{\(/}/}/}
      {/{/{\{\{\(/}{\{\/}/}{\}(_){\/}\}
      _{\{/{\{/(_)\}/}{/{/{/\}\})\}{/\}
     {/{/{\{\(/}{/{\{\{\/})/}{\(_)/}/}\}
      {\{\/}(_){\{\{\/}/}(_){\/}{\/}/})/}
       {/{\{\/}{/{\{\{\/}/}{\{\/}/}\}(_)
      {/{\{\/}{/){\{\{\/}/}{\{\(/}/}\}/}
       {/{\{\/}(_){\{\{\(/}/}{\(_)/}/}\}
         {/({/{\{/{\{\/}(_){\/}/}\}/}(\}
          (_){/{\/}{\{\/}/}{\{\)/}/}(_)
            {/{/{\{\/}{/{\{\{\(_)/}
             {/{\{\{\/}/}{\{\\}/}
              {){/ {\/}{\/} \}\}
              (_)  \.-'.-/
          __...--- |'-.-'| --...__
   _...--"   .-'   |'-.-'|  ' -.  ""--..__
 -"    ' .  . '    |.'-._| '  . .  '   ;-'
 .  '-  '    .--'  | '-.'|    .  '  . '
          ' ..     |'-_.-|
  .  '  .       _.-|-._ -|-._  .  '  .
              .'   |'- .-|   '.
  ..-'   ' .  '.   `-._.-'   .'  '  - .
   .-' '        '-._______.-'     '  .
        .      ~,
    .       .   |\   .    ' '-.
    ___________/  \____________
   /  Why is it, when you want \
  |  something, it is so damn   |
  |    much work to get it?     |
   \___________________________/)";

   file.close();
}