#include "library.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	ptr = (char *)malloc((ft_strlen(s) + 1) * sizeof(*s));
	if (!ptr)
		return (0);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
