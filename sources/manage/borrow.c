#include "library.h"

void	borrow_book(Library *lib)
{
	Book	*tmp;
	char	*input = NULL;
	char	*lowercase_input;
	char	*title;
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
		isbn = to_lowercase(tmp->isbn);
		if (!ft_strcmp(title, lowercase_input))
		{
			if (tmp->reserved && lib->user->reserved != tmp)
				printf("\t%sBook is reserved%s\n", ORANGE, RESET);
			else if (tmp->reserved && lib->user->reserved == tmp)
			{
				tmp->reserved = false;
				tmp->borrow = true;
				lib->user->borrow = tmp;
				lib->user->reserved = NULL;
				printf("\t%sDone ✅: Book is borrowed%s\n", GREEN, RESET);
			}
			else if (tmp->borrow)
				printf("\t%sBook is already borrowed%s\n", ORANGE, RESET);
			else if (lib->user->borrow)
				printf("\t%sYou can borrow only one book%s\n", ORANGE, RESET);
			else if (!lib->user->borrow)
			{
				tmp->borrow = true;
				lib->user->borrow = tmp;
				printf("\t%sDone ✅: Book is borrowed%s\n", GREEN, RESET);
			}
		}
		else if (!ft_strcmp(isbn, lowercase_input))
		{
			if (lib->user->borrow)
				printf("\t%sYou can borrow only one book%s\n", ORANGE, RESET);
			else if (tmp->reserved && lib->user->reserved != tmp)
				printf("\t%sBook is reserved%s\n", ORANGE, RESET);
			else if (tmp->reserved && lib->user->reserved == tmp)
			{
				tmp->reserved = false;
				tmp->borrow = true;
				lib->user->borrow = tmp;
				lib->user->reserved = NULL;
				printf("\t%sDone ✅: Book is borrowed%s\n", GREEN, RESET);
			}
			else if (tmp->borrow)
				printf("\t%sBook is already borrowed%s\n", ORANGE, RESET);
			else if (!lib->user->borrow)
			{
				tmp->borrow = true;
				lib->user->borrow = tmp;
				printf("\t%sDone ✅: Book is borrowed%s\n", GREEN, RESET);
			}
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
