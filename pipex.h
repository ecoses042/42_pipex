#ifndef	PIPEX_H
#define PIPEX_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>

#define NO_ARG "argument invalid\n"
#define NO_FILE "no such file or directory\n"
# define NO_FD "no fd available\n"
#define ALLOC_ERR "allocation error\n"
#define PIPE_ERR "error while creating a pipe\n"
#define PROC_ERR1 "error while executing first child process\n"
#define PARAM_ERR "invalid parameters\n"
#define NO_CMD "no command available\n"

//command executing related function
void	exe_command(char *cmd,char **envp);
char	*get_path(char *filename, char **envp);
char	*find_command(char **cmd, char **envp);
//utility
bool    print_error(char *status);
int	ft_strlen(const	char *a);
int openfile(char *av, bool mode);
char	**ft_split(char const *s, char c);
bool ft_strcmp(char *src, char *cmp);
char	*ft_strdup(const char *src, int ex_len);
char	*ft_strjoin(char const *s1, char const *s2);
void free_str_arr(char **tofree);
#endif