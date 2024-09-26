/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:45:17 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/09/26 19:43:47 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./Libft/libft.h"
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
char	**find_command(char *cmd, char **env);
void	first_son_process(char **argv, int *fd, char **env);
void	second_son_process(char **argv, int *fd, char **env);
char	*extract_path(char **env);
char	**executable_command(char *cmd, char **env);

#endif