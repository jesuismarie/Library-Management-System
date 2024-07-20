#include "library.h"

static void	help(void)
{
	printf("%s--------------------------------------------------------%s\n", ORANGE, RESET);
	printf("%s| Commands    | REGISTER    - Register new user        |%s\n", ORANGE, RESET);
	printf("%s|             | LOGIN       - Log in to personal page  |%s\n", ORANGE, RESET);
	printf("%s|             | ADD         - Add new book             |%s\n", ORANGE, RESET);
	printf("%s|             | SEARCH      - Search a book            |%s\n", ORANGE, RESET);
	printf("%s--------------------------------------------------------%s\n", ORANGE, RESET);
}

int	main(int argc, char **argv)
{
	Library	*lib = creat_lib();

	if (argc > 2)
	{
		printf("%sWrong count of arguments!!%s\n", RED, RESET);
		return (1);
	}
	if (argv[1] && (!ft_strcmp(argv[1], "-h") || !ft_strcmp(argv[1], "--help")))
		help();
	if (!parse_book(lib) || !parse_user(lib))
		return (1);
	enter_to_profile(lib);
	if (!lib->line)
	{
		clean(lib);
		return(0);
	}
	printf("\t%sWelcome to library :D%s\n", APPLE_GREEN, RESET);
	while (1)
	{
		lib->line = readline(PS);
		if (!lib->line)
			break ;
		manage(lib);
		free(lib->line);
	}
	clean(lib);
	return (0);
}