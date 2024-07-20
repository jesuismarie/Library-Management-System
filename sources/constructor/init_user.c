#include "library.h"

User	*create_user(char *username, char *password, bool flag)
{
	int		fd;
	User	*new_user;

	new_user = (User *)calloc(1, sizeof(User));
	if (!new_user)
		return (NULL);
	new_user->username = ft_strdup(username);
	new_user->password = ft_strdup(password);
	new_user->next = NULL;
	if (flag)
	{
		fd = open("database/users", O_APPEND | O_CREAT | O_WRONLY);
		ft_putstr_fd(username, fd);
		ft_putchar_fd(',', fd);
		ft_putendl_fd(password, fd);
		close(fd);
	}
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