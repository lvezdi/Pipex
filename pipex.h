/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:45:17 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/10/01 20:45:42 by lvez-dia         ###   ########.fr       */
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

void	first_son_process(char **argv, int *fd, char **env);
void	second_son_process(char **argv, int *fd, char **env);
char	*extract_path(char **env);
char	**find_command(char *cmd, char **env);

#endif