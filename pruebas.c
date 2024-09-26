/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:51:10 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/09/23 21:07:38 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
# include "./Libft/libft.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#define STDIN 0
#define STDOUT 1

char *get_path(char **env)
{
    int i = 0;
    char *path_prefix = "PATH=";

    while (env[i] != NULL)
    {
        if (ft_strncmp(env[i], path_prefix, ft_strlen(path_prefix)) == 0)
        {
            return (ft_strdup(env[i] + ft_strlen(path_prefix)));
        }
        i++;
    }
    return (NULL);
}


char	**generate_command(char *cmd, char **env)
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

void	first_son_process(char **argv, int *fd)
{
	int infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
	{
		perror("open infile");
		exit(EXIT_FAILURE);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);    // WTF?
    close(fd[1]);        
    generate_command(argv[2], (char **)NULL);
    perror("generate command");
    exit(EXIT_FAILURE);	
}

void	second_son_process(char **argv, int *fd)
{
	int outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
	{
		//  close(fd[0]);     ????????????
		perror("open outfile");
		exit(EXIT_FAILURE);
	}
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	dup2(fd[0], STDIN_FILENO);
    close(fd[0]);     
    close(fd[1]);    // WTF?
    generate_command(argv[3], (char **)NULL);
    perror("generate command");
    exit(EXIT_FAILURE);
}

int	Real_main(int argc, char **argv)
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
		first_son_process(argv, fd);
	pid2 = fork();
	if (pid2 == -1)
		return(1);
	if (pid2 == 0)
		second_son_process(argv, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (WEXITSTATUS(status));
}
