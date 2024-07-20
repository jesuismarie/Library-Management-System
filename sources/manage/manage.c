#include "library.h"

void	manage(Library *lib)
{
	if (!ft_strcmp(lib->line, "ADD"))
		add(lib);
	else
		printf("%sWrong Command ❌%s\n", RED, RESET);
	// else if (!ft_strcmp(lib->line, "SEARCH"))
	// {

	// }
}
