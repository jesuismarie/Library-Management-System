#include "library.h"

void	search(Library *lib)
{
	int		i = 0;
	Book	*tmp;
	char	*input;

	input = readline("Search: ");
	tmp = lib->books;
	while (tmp)
	{
		if (ft_strnstr(tmp->title, input, ft_strlen(tmp->title)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		else if (ft_strnstr(tmp->author, input, ft_strlen(tmp->author)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		else if (ft_strnstr(tmp->isbn, input, ft_strlen(tmp->isbn)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		tmp = tmp->next;
	}
	if (!i)
		printf ("\t%sNot Found%s\n", RED, RESET);
	free(input);
}
