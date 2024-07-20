#include "library.h"

void	manage(Library *lib)
{
	if (!ft_strcmp(lib->line, "ADD"))
		add(lib);
	else if (!ft_strcmp(lib->line, "SEARCH"))
		search(lib);
	else
		printf("%sWrong Command ❌%s\n", RED, RESET);
}
