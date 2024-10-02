/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:51:10 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/10/02 17:04:43 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "./Libft/libft.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

char	*extract_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", ft_strlen("PATH=")) == 0)
			return (ft_strdup(*env + 50));
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
	paths = ft_split(temp1, ':');
	free(temp1);
	comands = ft_split(cmd, ' ');
	if (!comands[0])
		return (free_split(paths), free_split(comands), NULL);
	while (paths && paths[i] != NULL)
	{
		temp1 = ft_strjoin(paths[i], "/");
		temp = ft_strjoin(temp1, comands[0]);
		free(temp1);
		if (access(temp, X_OK) == 0)
		{
			free(comands[0]);
			comands[0] = temp;
			return (free_split(paths), comands);
		}
		free(temp);
		i++;
	}
	if (paths)
		free_split(paths);
	return (comands);
}

void	first_son_process(char **argv, int *fd, char **env)
{
	int		infile;
	char	**comands;

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
	close(fd[0]);
	close(fd[1]);
	if (ft_strchr(argv[2], '/'))
		comands = ft_split(argv[2], ' ');
	else
		comands = find_command(argv[2], env);
	if (comands && comands[0])
		execve(comands[0],comands, env);
	if (comands)
		free_split(comands);
	exit(127);
}

void	second_son_process(char **argv, int *fd, char **env)
{
	int		outfile;
	char	**comands;

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
	if (ft_strchr(argv[3], '/'))
		comands = ft_split(argv[3], ' ');
	else
		comands = find_command(argv[3], env);
	if (comands && comands[0])
		execve(comands[0],comands, env);
	if (comands)
		free_split(comands);
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
