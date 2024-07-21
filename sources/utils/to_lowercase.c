#include "library.h"

char	*to_lowercase(char *str)
{
	int		i = -1;
	char	*tmp;

	tmp = ft_strdup(str);
	while (tmp[++i])
	{
		if (tmp[i] >= 'A' && tmp[i] <= 'Z')
			tmp[i] += 32;
	}
	return (tmp);
}
