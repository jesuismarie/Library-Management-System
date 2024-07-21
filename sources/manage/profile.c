#include "library.h"

void	enter_to_profile(Library *lib)
{
	bool	flag;
	printf("\n\t%sEnter REGISTER to create a personal profile%s\n", APPLE_GREEN, RESET);
	printf("\t%sAlready have a personal profile? Enter LOGIN%s\n\n", APPLE_GREEN, RESET);
	do
	{
		if (lib->line)
			free(lib->line);
		lib->line = readline(PS);
		flag = true;
		if (!lib->line)
		{
			clean(lib);
			exit(0);
		}
		if (!ft_strcmp(lib->line, "REGISTER"))
			lib_register(lib, &flag);
		else if (!ft_strcmp(lib->line, "LOGIN"))
			lib_login(lib, &flag);
		else
			printf("\t%sWrong Command: You must enter to profile ❌%s\n", RED, RESET);
	} while ((!flag) || (ft_strcmp(lib->line, "REGISTER") && ft_strcmp(lib->line, "LOGIN")));
	free(lib->line);
}

