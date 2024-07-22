#include "library.h"

bool	check_user(Library *lib, char *username)
{
	User	*tmp;

	if (!lib->users)
		return (true);
	tmp = lib->users;
	while (tmp)
	{
		if (!ft_strcmp(tmp->username, username))
		{
			printf("\t%sThis username is already taken, please choose another one.%s\n", ORANGE, RESET);
			return (false);
		}
		tmp = tmp->next;
	}
	return (true);
}

bool	check_login(Library *lib, char *str, bool *flag, User **user)
{
	User	*tmp;

	if (!lib->users)
	{
		printf("\t%sNo user found: Please register%s\n", ORANGE, RESET);
		*flag = false;
		return (false);
	}
	tmp = lib->users;
	while (tmp)
	{
		if (!ft_strcmp(tmp->username, str))
		{
			*user = tmp;
			return (true);
		}
		tmp = tmp->next;
	}
	printf("\t%sNo user found: Please register%s\n", ORANGE, RESET);
	*flag = false;
	return (false);
}

bool	check_password(User *user, char *password)
{
	char	*tmp;

	tmp = ft_strtrim(user->password, "\n");
	if (!ft_strcmp(tmp, password))
	{
		free(tmp);
		return (true);
	}
	free(tmp);
	printf("\t%sWrong password%s\n", RED, RESET);
	return (false);
}

User	*find_user(Library *lib, char *str)
{
	User	*tmp;

	tmp = lib->users;
	while (tmp)
	{
		if (!ft_strcmp(tmp->username, str))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
