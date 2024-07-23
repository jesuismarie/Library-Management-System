#include "library.h"

bool	parse_book(Library *lib)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**words;
	Book	*book;

	fd = open("database/books", O_RDONLY | O_CREAT);
	if(fd < 0)
		return (false);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strtrim(line, "\n ");
		free(line);
		words = ft_split(tmp, ',');
		if (!words && *words)
		{
			close(fd);
			return (false);
		}
		book = create_book(words[0], words[1], words[2], false);
		add_book(&lib->books, book);
		free(tmp);
		free_malloc(words);
	}
	close(fd);
	return (true);
}

bool	parse_user(Library *lib)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	**words;
	User	*user;

	fd = open("database/users", O_RDONLY | O_CREAT);
	if(fd < 0)
		return (false);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strtrim(line, "\n ");
		free(line);
		words = ft_split(tmp, ',');
		if (!words && *words)
		{
			close(fd);
			return (false);
		}
		user = create_user(words[0], words[1], false);
		add_user(&lib->users, user);
		free(tmp);
		free_malloc(words);
	}
	close(fd);
	return (true);
}
