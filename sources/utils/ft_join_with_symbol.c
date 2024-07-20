#include "library.h"

char	*join_with_symbol(char *s1, char *s2, char c)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (0);
	str = calloc(ft_strlen(s1) + ft_strlen(s2) + 2, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = c;
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
