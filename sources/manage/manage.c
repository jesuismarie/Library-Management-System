#include "library.h"

void	lib_loop(Library *lib)
{
	enter_to_profile(lib);
	if (!lib->line)
	{
		clean(lib);
		exit(0);
	}
	printf("\n\t%sWelcome to library :D%s\n\n", APPLE_GREEN, RESET);
	while (1)
	{
		lib->line = readline(PS0);
		if (!lib->line)
			break ;
		manage(lib);
		free(lib->line);
	}
}

void	manage(Library *lib)
{
	if (!ft_strcmp(lib->line, "ADD"))
		add(lib);
	else if (!ft_strcmp(lib->line, "SEARCH"))
		search(lib);
	else if (!ft_strcmp(lib->line, "LOGOUT"))
		lib_loop(lib);
	else if (!ft_strcmp(lib->line, "BORROW"))
		borrow_book(lib);
	else if (!ft_strcmp(lib->line, "RESERVE"))
		reserve_book(lib);
	else if (!ft_strcmp(lib->line, "RETURN"))
		return_book(lib);
	else if (!ft_strcmp(lib->line, "REMOVE"))
		user_remove_book(lib);
	else
		printf("\t%sWrong Command ❌%s\n", RED, RESET);
}
