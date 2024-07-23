#include "library.h"

void	return_book(Library *lib)
{
	Book	*tmp;
	char	*input = NULL;
	char	*lowercase_input;
	char	*title;
	char	*author;
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
		author = to_lowercase(tmp->author);
		isbn = to_lowercase(tmp->isbn);
		if (!ft_strcmp(title, lowercase_input))
		{
			book = to_lowercase(lib->user->borrow->title);
			if (!ft_strcmp(book, title))
			{
				tmp->borrow = 0;
				lib->user->borrow = NULL;
				printf("\t%sDone  ✅%s\n", GREEN, RESET);
			}
			else
				printf("\t%sYou don't borrow this book%s\n", ORANGE, RESET);
			free(book);
		}
		else if (!ft_strcmp(isbn, lowercase_input))
		{
			book = to_lowercase(lib->user->borrow->isbn);
			if (!ft_strcmp(book, isbn))
			{
				tmp->borrow = 0;
				lib->user->borrow = NULL;
				printf("\t%sDone  ✅%s\n", GREEN, RESET);
			}
			else
				printf("\t%sYou don't borrow this book%s\n", ORANGE, RESET);
			free(book);
		}
		free(title);
		free(author);
		free(isbn);
		tmp = tmp->next;
	}
	free(input);
	free(lowercase_input);
}
