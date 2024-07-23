#include "library.h"

void	borrow_book(Library *lib)
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
					printf("\t%sBook is already borrowed%s\n", ORANGE, RESET);
				else
					printf("\t%sBook is reserved%s\n", ORANGE, RESET);
				break ;
			}
			if (!lib->user->borrow)
			{
				tmp->borrow = 1;
				lib->user->borrow = tmp;
				printf("\t%sDone  ✅%s\n", GREEN, RESET);
			}
			else
				printf("\t%sYou can borrow only one book%s\n", ORANGE, RESET);
		}
		else if (!ft_strcmp(isbn, lowercase_input))
		{
			if (tmp->borrow || tmp->reserved)
			{
				free(title);
				free(author);
				free(isbn);
				if (tmp->borrow)
					printf("\t%sBook is already borrowed%s\n", ORANGE, RESET);
				else
					printf("\t%sBook is reserved%s\n", ORANGE, RESET);
				break ;
			}
			if (!lib->user->borrow)
			{
				tmp->borrow = 1;
				lib->user->borrow = tmp;
				printf("\t%sDone  ✅%s\n", GREEN, RESET);
			}
			else
				printf("\t%sYou can borrow only one book%s\n", ORANGE, RESET);
		}
		free(title);
		free(author);
		free(isbn);
		tmp = tmp->next;
	}
	free(input);
	free(lowercase_input);
}
