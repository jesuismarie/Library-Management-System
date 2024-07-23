#include "library.h"

void	user_remove_book(Library *lib)
{
	int		flag = 0;
	Book	*tmp;
	Book	*remove;
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
			if (tmp->borrow || tmp->reserved)
			{
				free(title);
				free(isbn);
				if (tmp->borrow)
					printf("\t%sYou can't remove this book: Book is borrowed%s\n", ORANGE, RESET);
				else
					printf("\t%sYou can't remove this book: Book is reserved%s\n", ORANGE, RESET);
				break ;
			}
			flag = 1;
			remove = tmp;
			tmp = tmp->next;
			remove_book(&lib->books, remove);
			lib->removed = 1;
			free(title);
			free(isbn);
			break ;
		}
		else if (!ft_strcmp(isbn, lowercase_input))
		{
			if (tmp->borrow || tmp->reserved)
			{
				free(title);
				free(isbn);
				if (tmp->borrow)
					printf("\t%sYou can't remove this book: Book is borrowed%s\n", ORANGE, RESET);
				else
					printf("\t%sYou can't remove this book: Book is reserved%s\n", ORANGE, RESET);
				break ;
			}
			flag = 1;
			remove = tmp;
			tmp = tmp->next;
			remove_book(&lib->books, remove);
			lib->removed = 1;
			free(title);
			free(isbn);
			break ;
		}
		free(title);
		free(isbn);
		if (!flag)
			tmp = tmp->next;
	}
	if (lib->removed)
		printf("\t%sDone ✅: Book removed successfully%s\n", GREEN, RESET);
	free(input);
	free(lowercase_input);
}
