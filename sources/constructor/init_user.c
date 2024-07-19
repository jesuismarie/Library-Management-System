#include "library.h"

User	*create_user(char *username, char *password)
{
	User	*new_user;

	new_user = (User *)calloc(1, sizeof(User));
	if (!new_user)
		return (NULL);
	new_user->username = ft_strdup(username);
	new_user->password = ft_strdup(password);
	new_user->next = NULL;
	return (new_user);
}

void	add_user(User **users, User *new_user)
{
	User	*tmp;

	if (!(*users))
	{
		*users = new_user;
		return ;
	}
	tmp = *users;
	while (tmp && tmp->next)
		tmp = tmp->next;
	tmp->next = new_user;
}