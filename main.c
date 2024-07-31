#include "pipex.h"

//argument:pipe fd, argv
//open infile with readonly
//close pipe_fd[0]
//set stdin to infile 0 
//set stdout to pipe_fd[1] 1
//find command number 1
//execute it
//pass it down the pipeline
void child(int *pipe_fd, char **av, char **envp)
{
	int fd;

	fd = openfile(av[1], 1);
	if (fd == -1)
	{
		print_error(NO_FILE);
		exit(0);
	}
	dup2(fd, 0);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[0]);
	exe_command(av[2], envp);
}

//open outfile with write
//close pipe_fd[1]
//set stdin to pipe_fd[0]
//set stdout to outfile
//find command number 2
//execute it
//pass it down to outfile
void parent(int *pipe_fd, char **av, char **envp)
{
	int fd;

	fd = openfile(av[4], 0);
	dup2(fd, 1);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[1]);
	exe_command(av[3], envp);
}
//needed test
//configure envp and find PATH line index v
//from PATH line index, find all the path v
//from that PATH directory, find if input exists v
//if does exist, create a char ** consisting of commands and infile path v
//execute command
//...
int main(int ac, char **av, char **envp)
{
	int p_fd[2];
	pid_t pid;

	if (ac != 5)
		return (print_error(NO_ARG));
	if (pipe(p_fd) == -1)
		return (print_error(PIPE_ERR));
	pid = fork();
	if (pid == -1)
		return (print_error(PROC_ERR1));
	if (pid == 0)
		child(p_fd, av, envp);
	parent(p_fd, av, envp);
	return (0);
}