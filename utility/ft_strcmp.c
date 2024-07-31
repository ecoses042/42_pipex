#include "../pipex.h"

bool ft_strcmp(char *src, char *cmp)
{
	int i;

	i = -1;
	if (ft_strlen(src) != ft_strlen(cmp))
		return (false);
	while (src[++i])
		if (src[i] != cmp[i])
			return  (false);
	return (true);
}