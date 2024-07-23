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
	int		fd;
	Book	*tmp;

	if (lib->removed)
	{
		fd = open("database/books", O_WRONLY | O_CREAT | O_TRUNC);
		tmp = lib->books;
		while (tmp)
		{
			ft_putstr_fd(tmp->title, fd);
			ft_putchar_fd(',', fd);
			ft_putstr_fd(tmp->author, fd);
			ft_putchar_fd(',', fd);
			ft_putendl_fd(tmp->isbn, fd);
			tmp = tmp->next;
		}
		close(fd);
	}
	tmp = NULL;
	while (lib->books)
	{
		tmp = lib->books->next;
		free(lib->books->title);
		free(lib->books->author);
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
