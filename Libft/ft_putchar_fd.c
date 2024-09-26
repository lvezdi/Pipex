/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:45:58 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/04/19 21:31:12 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd != 0)
		write(fd, &c, 1);
}

/*#include <fcntl.h>
int	main(void)
{
	char	c = 'M';
	int	fd;

	fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		return (0);
	else
	{
		ft_putchar_fd(c, fd);
		close(fd);
	}
	return (0);
}*/