#include "library.h"

void	borrow_book(Library *lib)
{
	Book	*tmp;
	char	*input = NULL;
	char	*lowercase_input;
	char	*title;
	char	*isbn;
	char	*reserved = NULL;

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
			if (lib->user->reserved)
				reserved = to_lowercase(lib->user->reserved->isbn);
			if (tmp->borrow || (tmp->reserved && reserved && ft_strcmp(reserved, title)))
			{
				free(title);
				free(isbn);
				if (tmp->borrow)
					printf("\t%sBook is already borrowed%s\n", ORANGE, RESET);
				else
					printf("\t%sBook is reserved%s\n", ORANGE, RESET);
				break ;
			}
			if (!lib->user->borrow && reserved && !ft_strcmp(reserved, title))
			{
				free(reserved);
				tmp->reserved = false;
				tmp->borrow = true;
				lib->user->borrow = tmp;
				lib->user->reserved = NULL;
			}
			else if (!lib->user->borrow)
			{
				tmp->borrow = true;
				lib->user->borrow = tmp;
				printf("\t%sDone ✅: Book is borrowed%s\n", GREEN, RESET);
			}
			else
				printf("\t%sYou can borrow only one book%s\n", ORANGE, RESET);
		}
		else if (!ft_strcmp(isbn, lowercase_input))
		{
			if (lib->user->reserved)
				reserved = to_lowercase(lib->user->reserved->isbn);
			if (tmp->borrow || (tmp->reserved && reserved && ft_strcmp(reserved, isbn)))
			{
				free(title);
				free(isbn);
				if (tmp->borrow)
					printf("\t%sBook is already borrowed%s\n", ORANGE, RESET);
				else
					printf("\t%sBook is reserved%s\n", ORANGE, RESET);
				break ;
			}
			if (!lib->user->borrow && reserved && !ft_strcmp(reserved, isbn))
			{
				free(reserved);
				tmp->reserved = false;
				tmp->borrow = true;
				lib->user->borrow = tmp;
				lib->user->reserved = NULL;
			}
			if (!lib->user->borrow)
			{
				tmp->borrow = true;
				lib->user->borrow = tmp;
				printf("\t%sDone ✅: Book is borrowed%s\n", GREEN, RESET);
			}
			else
				printf("\t%sYou can borrow only one book%s\n", ORANGE, RESET);
		}
		free(title);
		free(isbn);
		tmp = tmp->next;
	}
	if (!lib->user->borrow)
		printf("\t%sSorry, We don't have this book%s\n", ORANGE, RESET);
	free(input);
	free(lowercase_input);
}
