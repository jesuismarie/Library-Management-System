#include "library.h"

void	return_book(Library *lib)
{
	Book	*tmp;
	char	*input = NULL;
	char	*lowercase_input;
	char	*title;
	char	*isbn;
	char	*book;

	if (!lib->books)
	{
		printf("\t%sThere are no books%s\n", ORANGE, RESET);
		return ;
	}
	do
	{
		if (input)
			free(input);
		input = readline(PS2);
		if (!input)
			return ;
	} while (!ft_strcmp(input, ""));
	lowercase_input = to_lowercase(input);
	tmp = lib->books;
	while (tmp)
	{
		title = to_lowercase(tmp->title);
		isbn = to_lowercase(tmp->isbn);
		if (!ft_strcmp(title, lowercase_input))
		{
			if (lib->user->borrow)
			{
				book = to_lowercase(lib->user->borrow->title);
				if (!ft_strcmp(book, title))
				{
					tmp->borrow = false;
					lib->user->borrow = NULL;
					printf("\t%sDone ✅: Book is returned%s\n", GREEN, RESET);
				}
				free(book);
			}
			else
				printf("\t%sYou don't borrow this book%s\n", ORANGE, RESET);
		}
		else if (!ft_strcmp(isbn, lowercase_input))
		{
			if (lib->user->borrow)
			{
				book = to_lowercase(lib->user->borrow->isbn);
				if (!ft_strcmp(book, isbn))
				{
					tmp->borrow = false;
					lib->user->borrow = NULL;
					printf("\t%sDone ✅: Book is returned%s\n", GREEN, RESET);
				}
				free(book);
			}
			else
				printf("\t%sYou don't borrow this book%s\n", ORANGE, RESET);
		}
		free(title);
		free(isbn);
		tmp = tmp->next;
	}
	free(input);
	free(lowercase_input);
}
