#include "../pipex.h"

//call this function with mode 0 if child, 1 for parent
//if mode is 0, stdin 1 for stdout
int openfile(char *av, bool mode)
{
	int fd;

	if (!mode)
		fd = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		fd = open(av, O_RDONLY, 0777);
	if (fd == -1)
		print_error(NO_FILE);
	return (fd);
}