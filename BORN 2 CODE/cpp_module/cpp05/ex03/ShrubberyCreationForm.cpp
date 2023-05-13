#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	:AForm("UNKNWON", "ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:AForm(target, "ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source)
	:AForm(source)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator = (const ShrubberyCreationForm &source)
{
	if (this == &source)
		return (*this);
	return (*dynamic_cast<ShrubberyCreationForm *>(&AForm::operator=(source)));
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	executalbe(executor);
	const std::string tree = "               ,@@@@@@@,\n"
                          "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
                          "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
                          "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
                          "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
                          "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
                          "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
                          "       |o|        | |         | |\n"
                          "       |.|        | |         | |\n"
                          "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_";
	std::ofstream out;
	out.open(getTarget() + "_shrubbery");
	if (out.fail())
		throw FileOpenException();
	else
		out << tree << std::endl;
	out.close();
}
