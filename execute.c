#include "pipex.h"

void execute_command(char *command)
{
	char **args;

	args = ft_split(command, ' ');
	execve(args[0], args, NULL);
	
}