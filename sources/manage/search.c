#include "library.h"

void	search(Library *lib)
{
	int		i = -1;
	Book	*tmp;
	char	**input;

	tmp = lib->books;
	while (tmp)
	{
		if (ft_strnstr(tmp->title, lib->line, ft_strlen(lib->line)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		else if (ft_strnstr(tmp->author, lib->line, ft_strlen(lib->line)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		else if (ft_strnstr(tmp->isbn, lib->line, ft_strlen(lib->line)))
			printf("%d. %s, %s, %s\n", ++i, tmp->title, tmp->author, tmp->isbn);
		tmp = tmp->next;
	}
}
