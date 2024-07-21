#include "library.h"

void	search(Library *lib)
{
	int		i = 0;
	Book	*tmp;
	char	*input = NULL;
	char	*lowercase_input;
	char	*title;
	char	*author;
	char	*isbn;

	do
	{
		if (input)
			free(input);
		input = readline("Search: ");
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
		if (ft_strnstr(title, input, ft_strlen(tmp->title)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		else if (ft_strnstr(author, input, ft_strlen(tmp->author)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		else if (ft_strnstr(isbn, input, ft_strlen(tmp->isbn)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		free(title);
		free(author);
		free(isbn);
		tmp = tmp->next;
	}
	if (!i)
		printf ("\t%sNot Found%s\n", RED, RESET);
	free(input);
	free(lowercase_input);
}
