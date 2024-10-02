/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:44:41 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/10/02 19:45:17 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*extract_path(char **env)
{
	while (*env)
	{
		if (ft_strncmp(*env, "PATH=", ft_strlen("PATH=")) == 0)
			return (ft_strdup(*env + 5));
		env++;
	}
	return (NULL);
}

char	**get_commands(char *cmd)
{
	char	**comands;

	comands = ft_split(cmd, ' ');
	if (!comands[0])
		return (free_split(comands), NULL);
	return (comands);
}
char	**search_command_in_paths(char **paths, char **comands)
{
	int		i;
	char	*temp1;
	char	*temp;

	i = 0;
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

char	**find_command(char *cmd, char **env)
{
	char	*temp1;
	char	**paths;
	char	**comands;

	temp1 = extract_path(env);
	paths = ft_split(temp1, ':');
	free(temp1);
	comands = get_commands(cmd);
	if (!comands)
		return (free_split(paths), NULL);
	return (search_command_in_paths(paths, comands));
}