#include "library.h"

void	lib_register(Library *lib, bool *flag)
{
	char	*username = NULL;
	char	*pass = NULL;
	char	*tmp = NULL;
	User	*new_user;

	(void)flag;
	do
	{
		if (username)
			free(username);
		username = readline("Enter username: ");
		if (!username)
		{
			*flag = false;
			return ;
		}
	} while (!check_user(lib, username) || !ft_strcmp(username, ""));
	do
	{
		if (pass)
			free(pass);
		disable_echo();
		pass = readline("Enter password: ");
		enable_echo();
		if (!pass)
		{
			free(username);
			*flag = false;
			return ;
		}
	} while (!ft_strcmp(pass, ""));
	do
	{
		if (tmp)
		{
			printf("\t%sPassword didn't match%s\n", RED, RESET);
			free(tmp);
		}
		disable_echo();
		tmp = readline("Re-enter password: ");
		enable_echo();
		if (!tmp)
		{
			free(username);
			free(pass);
			*flag = false;
			return ;
		}
	} while (ft_strcmp(pass, tmp));
	new_user = create_user(username, pass, 1);
	add_user(&lib->users, new_user);
	lib->user = find_user(lib, username);
	free(username);
	free(pass);
	free(tmp);
}
