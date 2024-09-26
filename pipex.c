/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:51:18 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/09/26 17:41:55 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#define STDIN 0
#define STDOUT 1

/*char	**generate_command(char *cmd, char **env)
{
	char	*temp1;
	char	**paths;
	char	**comands;
	int		i;
	char	*temp;

	i = 0;
	temp1 = get_path(env);
	paths = ft_split(temp1, ':'); //home/lvez-dia/bin:/home/lvez-dia/bin... -> paths[0]="/home/lvez-dia/bin" paths[1]="/home/lvez-dia/bin"..... paths[n] =NULL 
	free(temp1);
	comands = ft_split(cmd, ' ');// ls -la -> commands[0] = "ls" commands[1]"-la" commands[2]= NULL

// ls -> /home/lvez-dia/bin ls
// ls -> /home/lvez-dia/bin/ls
	while (paths[i++] != NULL)
	{
		temp1 = ft_strjoin(paths[i], "/");// paths[0]="/home/lvez-dia/bin" + "/"" = "ls" -> temp = /home/lvez-dia/bin/
		temp = ft_strjoin(temp1, comands[0]);// "/home/lvez-dia/bin/" + "ls"" = "ls" -> temp = /home/lvez-dia/bin/ls
		free(temp1);
		if (access(temp, X_OK == 0))
		{
			//libero paths, Libero
			//free_p2(paths);
			free(comands[0]);
			comands[0] = temp;
			return (comands);
		}
	}
	return (comands);
}

pid_t ft_executepid(int fd_pid[2], char *cmd, char **env)
{
	pid_t pid;
	char **command;

	pid = fork();
	if (pid == -1)
	{

	}
	else if (pid == 0)
	{
		printf("numero de fds: %d", fd_pid[1]);
		printf("numero de fds: %d", fd_pid[0]);
		dup2(fd_pid[0], STDIN_FILENO);
		dup2(fd_pid[1], STDOUT_FILENO);
		if (fd_pid[0] != 0)
			close(fd_pid[0]);
		if (fd_pid[1] != 1)
			close(fd_pid[1]);
		command = generate_command(cmd);
		if (execve(command[0], command, env) == -1)
			(printf("%s\n", strerror(errno)), exit(127));
	}
}

int main6(int argc, char **argv, char **env)
{

		pid_t pid;
		pid_t	pid2;
		int status;
		int fds[2];
		int fd_pid[2];

		char *infile;
		char *outfile;
		if(argc != 5)
			return (0);
		
		infile = argv[1];
		outfile = argv[4];
		status = 0;
		pipe(fds);
		fd_pid[STDIN] = open(infile, O_RDONLY);
		fd_pid[STDOUT] = fds[STDOUT];
		pid = ft_executepid(fd_pid, argv[2], env);
		close(fd_pid[STDIN]);
		close(fd_pid[STDOUT]);
		fd_pid[STDIN] = fds[STDIN];
		fd_pid[STDOUT] = open(outfile, O_WRONLY | O_CREAT, 0644);
		pid2 = ft_executepid(fd_pid, argv[3], env);
		if (fd_pid[STDIN] != STDIN_FILENO)
			close(fd_pid[STDIN]);
		if (fd_pid[STDOUT] != STDOUT_FILENO)
			close(fd_pid[STDOUT]);
		waitpid(pid, &status, 0);
		printf("EStado de finalizacion del pid: %d\n", WEXITSTATUS(status));
		waitpid(pid2, &status, 0);
		printf("EStado de finalizacion del pid1: %d\n", WEXITSTATUS(status));
}*/
