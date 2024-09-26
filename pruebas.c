/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:51:10 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/09/26 19:45:30 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
# include "./Libft/libft.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

void	ft_free_p2(char **p2)
{
	int	i;

	i = 0;
	while (p2[i])
		free(p2[i++]);
	free(p2);
}

static int	do_exec(char *line, char **env)
{
	char	**command;

	command = ft_split(line, ' ');
	if (!command)
		(perror("Memory error: "));
	if (*command == 0)
		return (ft_free_p2(command), -1);//libera el split
	if ((access(command[0], F_OK | X_OK) == 0) \
	&& ft_strnstr(command[0], "./", 2))
	{
		if (execve(command[0], command, env) == -1)
			return (ft_free_p2(command), -1);
	}
	else if (access(command[0], F_OK | X_OK) != 0 && ft_strchr(command[0], '/'))
		return (ft_free_p2(command), -1);
	else
	{
		ft_free_p2(command);
		command = find_command(line, env);
		if (command[0] == NULL || execve(command[0], command, env) == -1)
			return (ft_free_p2(command), -1);
	}
	return (0);
}


char *extract_path(char **env)
{
    while (*env)
	{
		if (ft_strncmp(*env, "PATH=", ft_strlen("PATH=")) == 0)
			return ft_strdup(*env + 5);
        env++;
    }
    return (NULL);
}


char	**find_command(char *cmd, char **env)
{
	char	*temp1;
	char	**paths;
	char	**comands;
	int		i;
	char	*temp;

	i = 0;
	temp1 = extract_path(env);
	paths = ft_split(temp1, ':'); //home/lvez-dia/bin:/home/lvez-dia/bin... -> paths[0]="/home/lvez-dia/bin" paths[1]="/home/lvez-dia/bin"..... paths[n] =NULL 
	free(temp1);
	comands = ft_split(cmd, ' ');// ls -la -> commands[0] = "ls" commands[1]"-la" commands[2]= NULL

// ls -> /home/lvez-dia/bin ls
// ls -> /home/lvez-dia/bin/ls
	while (paths[i] != NULL)
	{
		temp1 = ft_strjoin(paths[i], "/");// paths[0]="/home/lvez-dia/bin" + "/"" = "ls" -> temp = /home/lvez-dia/bin/
		temp = ft_strjoin(temp1, comands[0]);// "/home/lvez-dia/bin/" + "ls"" = "ls" -> temp = /home/lvez-dia/bin/ls
		free(temp1);
		if (access(temp, X_OK) == 0)
		{
			free(comands[0]);
			comands[0] = temp;
			free(paths);
			return (comands);
		}
		free(temp);
		i++;
	}
	free(paths);
	return (comands);
}

void	first_son_process(char **argv, int *fd, char **env)
{
	int		infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("open infile");
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
    (close(fd[0]), close(fd[1]));
	do_exec(argv[2], env);
    perror("generate command");
    exit(127);	
}

void	second_son_process(char **argv, int *fd, char **env)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		close(fd[0]);
		close(fd[1]);
		perror("open outfile");
		exit(EXIT_FAILURE);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	dup2(fd[0], STDIN_FILENO);
    close(fd[0]);     
    close(fd[1]);
	do_exec(argv[3], env);
    perror("generate command");
    exit(127);
}

int	main(int argc, char **argv, char **env)
{
	pid_t	pid1;
	pid_t	pid2;
	int		fd[2];
	int		status;

	if(argc != 5)
		return (0);
	if (pipe(fd) == -1)
		return (0);
	pid1 = fork();
	if (pid1 == -1)
		return(1);
	if (pid1 == 0)
		first_son_process(argv, fd, env);
	pid2 = fork();
	if (pid2 == -1)
		return(1);
	if (pid2 == 0)
		second_son_process(argv, fd, env);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}
