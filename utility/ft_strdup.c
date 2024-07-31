#include "../pipex.h"

char	*ft_strdup(const char *src, int ex_len)
{
	char	*cpy;
	int		i;
	int		len;

	len = ft_strlen(src) - ex_len;
	i = -1;
	cpy = (char *)malloc(len + 1);
	if (!cpy)
		return (0);
	while (src[++i + ex_len])
		cpy[i] = src[i + ex_len];
	cpy[i] = '\0';
	return (cpy);
}