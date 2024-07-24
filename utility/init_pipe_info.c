#include "../pipex.h"

void init_pipe_info(t_pipe_info *param)
{
	param->fd1 = 0;
	param->fd2 = 0;
	param->command = NULL;
}