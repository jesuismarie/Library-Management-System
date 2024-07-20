#include "library.h"

Book	*create_book(char *title, char *author, char *isbn, bool flag)
{
	int		fd;
	Book	*new_book;

	new_book = (Book *)calloc(1, sizeof(Book));
	if (!new_book)
		return (NULL);
	new_book->title = ft_strdup(title);
	new_book->author = ft_strdup(author);
	new_book->isbn = ft_strdup(isbn);
	new_book->borrow = false;
	new_book->reserved = false;
	new_book->next = NULL;
	if (flag)
	{
		fd = open("database/books", O_APPEND | O_WRONLY);
		ft_putstr_fd(title, fd);
		ft_putchar_fd(',', fd);
		ft_putstr_fd(author, fd);
		ft_putchar_fd(',', fd);
		ft_putendl_fd(isbn, fd);
		close(fd);
	}
	return (new_book);
}

void	add_book(Book **books, Book *new_book)
{
	Book	*tmp;

	if (!(*books))
	{
		*books = new_book;
		return ;
	}
	tmp = *books;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new_book;
}

void	remove_book(Book **books, Book *book)
{
	Book	*tmp;
	Book	*temp;

	if (!(*books))
	{
		printf("Library don't have any books\n");
		return ;
	}
	tmp = *books;
	while (tmp)
	{
		if (tmp == book)
		{
			temp = tmp->next;
			free(tmp->title);
			free(tmp->author);
			free(tmp->isbn);
			free(tmp);
			tmp = temp;
			break ;
		}
		tmp = tmp->next;
	}
}
