#include "library.h"

void	lib_login(Library *lib, bool *flag)
{
	char	*username = NULL;
	char	*pass = NULL;
	User	*user;

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
	} while (!ft_strcmp(username, ""));
	if (!check_login(lib, username, flag, &user))
	{
		free(username);
		return ;
	}
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
	} while (!check_password(user, pass) || !ft_strcmp(pass, ""));
	free(username);
	free(pass);
}
