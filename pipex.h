/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:45:17 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/09/23 21:07:55 by lvez-dia         ###   ########.fr       */
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

// int main2(int argc, char **argv, char **env);
// pid_t ft_executepid(int fd_pid[2], char **cmd, char **env);
// int main(int argc, char **argv, char **env);
// int main1(int argc, char **argv, char **env);
// pid_t ft_executepid(int fd_pid[2], char **cmd, char **env);
// int main6(int argc, char **argv, char **env);
void	first_son_process(char **argv, int *fd);
void	second_son_process(char **argv, int *fd);
int		Real_main(int argc, char **argv);
char *get_path(char **env);
char	**generate_command(char *cmd, char **env);

#endif