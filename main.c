/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:51:31 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/09/23 17:51:32 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main2(int argc, char **argv, char **env)
{
	// no estamos utilizando en los parametros los argc argv y env

		pid_t pid;
		pid_t	pid1;
		int status; // almacena el estado del hijo

		// ¿por que dos hijos?

		status = 0;

		pid = fork();
		if (pid == -1)
		{
			//perror("fork");
			//return(1);
		}
		else if (pid == 0)
		{
			exit(1);
		}
		pid1 = fork();
		if (pid1 == -1)
		{
			//perror("fork");
			//return(1);
		}
		else if (pid1 == 0)
		{







			exit(2); // 0 es el hijo, y el padre (numeros positivos)?
			// cual es el pid padre y el pid hijo? --> no se necesita proceso padre porque
			// el padre es el original? 
			// se podria hacer en dos procesos: proceso_padre(waitpid) y proceso_hijo
		}

		waitpid(pid, &status, 0);
		printf("EStado de finalizacion del pid: %d\n", WEXITSTATUS(status));
		waitpid(pid1, &status, 0);
		printf("EStado de finalizacion del pid1: %d\n", WEXITSTATUS(status));

}
pid_t generate_pid(void *(*f)(void *), void * data)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		// por que el mismo proceso tantas veces? 
	}
	else if (pid == 0)
	{
		f(data);
		exit(0);
	}
}
pid_t ft_executepid(int fd_pid[2], char *cmd, char **env)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		// por que el mismo proceso tantas veces? 
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
		ft_split(cmd, ' ');
		if (execve(cmd[0], cmd, env) == -1)
			(printf("%s\n", strerror(errno)), exit(127));
	}
}

int main(int argc, char **argv, char **env)
{

		pid_t pid;
		pid_t	pid1;
		int status;
		int fds[2];
		int init_fd[2];

		char *infile = "infile";
		char *outfile = "outfile";


		status = 0;
		pipe(fds);
		init_fd[0] = 0;
		init_fd[1] = fds[1];
		ft_executepid(init_fd,(char *[]){"/usr/bin/ls", "-l", NULL}, env);
		// entiendo que lo anterior no puedo utilizarlo 
		// por lo cual tendré que utilizar el split
		close(init_fd[0]); 
		init_fd[0] = fds[0];
		init_fd[1] = 1;
		ft_executepid(init_fd, (char *[]){"/usr/bin/cat", "-e", NULL}, env);
		if (init_fd[0] != 0)
			close(init_fd[0]);
		if (init_fd[1] != 1)
			close(init_fd[1]);

		waitpid(pid, &status, 0);
		printf("EStado de finalizacion del pid: %d\n", WEXITSTATUS(status));
		waitpid(pid1, &status, 0);
		printf("EStado de finalizacion del pid1: %d\n", WEXITSTATUS(status));

}

int main1(int argc, char **argv, char **env)
{

	int infile = open("temp",O_RDONLY, 0777);
	int outfile = open("temp2", O_WRONLY | O_CREAT, 0777);

	dup2(infile, STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	if (execve("/usr/bin/cat", (char *[]){"cat","-e", NULL}, env) == -1)
		(printf("%s\n", strerror(errno)), exit(127));
}
