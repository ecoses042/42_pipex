#include "../pipex.h"

char *envp_name(char *envp)
{
	int i;
	int len;
	char *result;

	i = -1;
	len = 0;
	while (envp[++i] != '=')
		len++;
	result = malloc(sizeof(char) * (len));
	result[len] = '\0';
	len--;
	while (len > -1)
	{
		result[len] = envp[len];
		len--;
	}
	return (result);
}
//find specific filename in envp.
//PATH for example.
char *get_path(char *filename, char **envp)
{
	int i;
	char *result;

	i = -1;
	result = NULL;
	while (envp[++i])
	{
		if (ft_strcmp(envp_name(envp[i]), filename))
		{
			result = ft_strdup(envp[i], ft_strlen(filename) + 1);
			break;
		}
	}
	return (result);
}

//split the command
//check if valid command
//execute command

//this function will find path to command
//parameter:commandline, envp
//split the command by ' '
//find path of that command
char *find_command(char **cmd, char **envp)
{
	int		i;
	char	*command;
	char	*command_path;
	char	**path;

	path = ft_split(get_path("PATH", envp), ':');
	i = -1;
	while (path[++i])
	{
		command_path = ft_strjoin(path[i], "/");
		command = ft_strjoin(command_path, cmd[0]);
		free(command_path);
		//check if file is there
		if (!access(command, F_OK | X_OK))
		{
			//free path and p_command
			free_str_arr(path);
			return (command);
		}
		free(command);
	}
	free_str_arr(path);
	//if command is not found,, free p_command anad path
	return (cmd[0]);
}

void	exe_command(char *cmd,char **envp)
{
	char	*com_path;
	char	**s_cmd;

	s_cmd = ft_split(cmd, ' ');
	com_path = find_command(s_cmd, envp);
	if (execve(com_path, s_cmd, envp) == -1)
	{
		print_error(NO_CMD);
		free_str_arr(s_cmd);
		free(com_path);
		exit(0);
		return ;
	}
	free_str_arr(s_cmd);
	free(com_path);
}