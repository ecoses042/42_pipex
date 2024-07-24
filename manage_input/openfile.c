#include "../pipex.h"

bool init_file(t_pipe_info *param, char **av)
{
	param->infile = open(av[1], O_RDONLY);
	if (param->infile < 0)
		return (print_error(NO_FILE));
	param->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (param->outfile < 0)
	{
		ft_close(param, 1);
		return (print_error(NO_FILE));
	}
	
	if (pipe(param->pipe_fd) < 0)
	{
		ft_close(param, 2);
		return (print_error(PIPE_ERR));
	}
	if (!init_first(param, av))
		return (print_error(PROC_ERR1));
	//pipe the process
	//fork the child process
	//check the first child 
	//fork the second child process
	//check the second child process
}