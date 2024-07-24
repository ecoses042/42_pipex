#include "pipex.h"

int main(int ac, char **av)
{
	t_pipe_info process;

	if (ac != 5)
		return (print_error(PARAM_ERR));
	init_pipe_info(&process);
	if (!init_file(&process, av))
		return (1);
	return (0);
}