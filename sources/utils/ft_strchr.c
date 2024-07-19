#include "library.h"

char	*ft_strchr(const char *s, int c)
{
	char	b;

	b = (char)c;
	if (!s)
		return (0);
	while (*s && *s != b)
		s++;
	if (*s == b)
		return ((char *)s);
	return (0);
}
