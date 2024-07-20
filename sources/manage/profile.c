#include "library.h"

void	enter_to_profile(Library *lib)
{
	printf("\n\t%sEnter REGISTER to create a personal profile%s\n", GREEN, RESET);
	printf("\t%sAlready have a personal profile? Enter LOGIN%s\n\n", GREEN, RESET);
	do
	{
		if (lib->line)
			free(lib->line);
		lib->line = readline(PS);
		if (!lib->line)
		{
			clean(lib);
			exit(0);
		}
		if (!ft_strcmp(lib->line, "REGISTER"))
		{
			
		}
		else if (!ft_strcmp(lib->line, "LOGIN"))
		{

		}
		else
			printf("%sWrong Command: You must enter to profile ❌%s\n", RED, RESET);
	} while (ft_strcmp(lib->line, "REGISTER") && ft_strcmp(lib->line, "LOGIN"));
	free(lib->line);
}

