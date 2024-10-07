/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:45:17 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/10/07 13:15:42 by lvez-dia         ###   ########.fr       */
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

void	first_son_process(char **argv, int *fd, char **env);
void	second_son_process(char **argv, int *fd, char **env);
char	*extract_path(char **env);
char	**find_command(char *cmd, char **env);
char	**get_commands(char *cmd);
char	**search_command_in_paths(char **paths, char **comands);

#endif