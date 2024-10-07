/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:11:37 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/10/07 13:19:47 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
/*int	main(void)
{
	char	str[] = "42 Madrid";
	char	c = 'a';
	size_t	len = 6;

	printf("Original text: %s\n",str);
	ft_memset(str, c, len);
	printf("Final text: %s\n", str);
	return (0);
}*/
