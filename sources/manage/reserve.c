#include "library.h"

void	reserve_book(Library *lib)
{
	Book	*tmp;
	char	*input = NULL;
	char	*lowercase_input;
	char	*title;
	char	*author;
	char	*isbn;

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
			if (tmp->borrow || tmp->reserved)
			{
				free(title);
				free(author);
				free(isbn);
				if (tmp->borrow)
					printf("\t%sBook is borrowed%s\n", ORANGE, RESET);
				else
					printf("\t%sBook is already reserved%s\n", ORANGE, RESET);
				break ;
			}
			if (!lib->user->reserved)
			{
				tmp->reserved = true;
				lib->user->reserved = tmp;
				printf("\t%sDone ✅: Book is reserved%s\n", GREEN, RESET);
			}
			else
				printf("\t%sYou can reserve only one book%s\n", ORANGE, RESET);
		}
		else if (!ft_strcmp(isbn, lowercase_input))
		{
			if (tmp->borrow || tmp->reserved)
			{
				free(title);
				free(author);
				free(isbn);
				if (tmp->borrow)
					printf("\t%sBook is borrowed%s\n", ORANGE, RESET);
				else
					printf("\t%sBook is already reserved%s\n", ORANGE, RESET);
				break ;
			}
			if (!lib->user->reserved)
			{
				tmp->reserved = true;
				lib->user->reserved = tmp;
				printf("\t%sDone ✅: Book is reserved%s\n", GREEN, RESET);
			}
			else
				printf("\t%sYou can reserve only one book%s\n", ORANGE, RESET);
		}
		free(title);
		free(author);
		free(isbn);
		tmp = tmp->next;
	}
	if (!lib->user->reserved)
		printf("\t%sSorry, We don't have this book%s\n", ORANGE, RESET);
	free(input);
	free(lowercase_input);
}
