/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:15:45 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:25:04 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}
/*int	main(void)
{
	char	str[] = "42 Madrid";
	size_t	len = 3;

	printf("Original: %s\n", str);
	ft_bzero(str, len);
	printf("Final text: %s\n", str);
	return (0);
}*/
