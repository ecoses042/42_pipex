#ifndef PIPEX_H
#define	PIPEX_H

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define NO_FILE "check file path"
#define ALLOC_ERR "allocation error"
#define PIPE_ERR "error while creating a pipe"
#define PROC_ERR1 "error while executing first child process"
#define PROC_ERR2 "error while executing second child process"
#define PARAM_ERR "invalid parameters"

//struct for fd and command line

typedef struct s_pipe_info{
	int infile;
	int outfile;
    int pipe_fd[2];
    pid_t pid1;
    pid_t pid2;
}t_pipe_info;


//manage_input
bool init_file(t_pipe_info *param, char **av);

//utility
bool    print_error(char *status);
int	ft_strlen(const	char *a);
void init_pipe_info(t_pipe_info *param);
void ft_cloase(t_pipe_info *param, int mode);

#endif