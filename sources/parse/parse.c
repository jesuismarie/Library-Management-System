#include "library.h"

bool	parse_book(Library *lib)
{
	int		fd;
	char	*line;
	char	**words;
	Book	*book;

	fd = open("database/data", O_RDONLY);
	if(fd < 0)
		return (false);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		words = ft_split(line, ',');
		if (!words && *words)
			return (false);
		book = create_book(words[0], words[1], words[2]);
		add_book(&lib->books, book);
		free(line);
		free_malloc(words);
	}
	return (true);
}

bool	parse_user(Library *lib)
{
	int		fd;
	char	*line;
	char	**words;
	User	*user;

	fd = open("database/data", O_RDONLY);
	if(fd < 0)
		return (false);
	while(1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		words = ft_split(line, ',');
		if (!words && *words)
			return (false);
		user = create_user(words[0], words[1]);
		add_user(&lib->users, user);
		free(line);
		free_malloc(words);
	}
	return (true);
}
