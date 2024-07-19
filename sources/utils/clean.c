#include "library.h"

int	free_malloc(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
	return (1);
}

void	free_books(Library *lib)
{
	Book	*tmp;

	while (lib->books)
	{
		tmp = lib->books->next;
		free_malloc(lib->books->title);
		free_malloc(lib->books->author);
		free(lib->books->isbn);
		free(lib->books);
		lib->books = tmp;
	}
}

void	free_users(Library *lib)
{
	User	*tmp;

	while (lib->users)
	{
		tmp = lib->users->next;
		free(lib->users->username);
		free(lib->users->password);
		free(lib->users);
		lib->users = tmp;
	}
}

void	clean(Library *lib)
{
	free_books(lib);
	free_users(lib);
	free(lib);
}
