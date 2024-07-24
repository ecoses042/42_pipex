#include "../pipex.h"

//1 for close infile
//2 outfile
//
void ft_cloase(t_pipe_info *param, int mode)
{
	if (mode > 0)
		close(param->infile);
	if (mode > 1)
		close(param->outfile);
	if (mode > 2)
	{
		close(param->pipe_fd[0]);
		close(param->pipe_fd[1]);
	}
}