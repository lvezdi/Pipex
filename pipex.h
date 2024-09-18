/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:45:17 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/09/18 19:24:33 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# define READ 0
# define WRITE 1

int main2(int argc, char **argv, char **env);
pid_t ft_executepid(int fd_pid[2], char **cmd, char **env);
int main(int argc, char **argv, char **env);
int main1(int argc, char **argv, char **env);
pid_t ft_executepid(int fd_pid[2], char **cmd, char **env);
int main6(int argc, char **argv, char **env);

#endif