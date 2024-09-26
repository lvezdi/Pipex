/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:09:17 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/04/28 13:21:32 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (fd != 0 && s != 0)
	{
		write(fd, s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
/*int main()
{
	ft_putendl_fd(NULL, -1);
	return 0;
}*/