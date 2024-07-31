#include "../pipex.h"

void free_str_arr(char **tofree)
{
	int i;

	i = -1;
	while (tofree[++i])
		free(tofree[i]);
	free(tofree);	
}