#include "library.h"

void	add(Library *lib)
{
	char	*title = NULL;
	char	*author = NULL;
	char	*isbn = NULL;
	Book	*new_book;

	do
	{
		if (title)
			free(title);
		title = readline("Enter title: ");
		if (!title)
			return ;
	} while (!ft_strcmp(title, ""));
	do
	{
		if (author)
			free(author);
		author = readline("Enter author: ");
		if (!author)
		{
			free(title);
			return ;
		}
	} while (!ft_strcmp(author, ""));
	do
	{
		if (isbn)
			free(isbn);
		isbn = readline("Enter isbn: ");
		if (!isbn)
		{
			free(title);
			free(author);
			return ;
		}
	} while (!ft_strcmp(isbn, ""));
	new_book = create_book(title, author, isbn, 1);
	add_book(&lib->books, new_book);
	printf("\t%sDone ✅: Book added successfully%s\n", GREEN, RESET);
	free(title);
	free(author);
	free(isbn);
}
