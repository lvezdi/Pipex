/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:12:25 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:33:16 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	i = 0;
	if (dst < src)
	{
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (dst > src)
	{
		i = len -1;
		while (len--)
		{
			d[i] = s[i];
			i--;
		}
	}
	return (dst);
}
/*int	main(void)
{
	char	src[] = "42 Madrid";
	char	dest[] = "Cursus";
	ft_memmove(dest, src, sizeof(src));
	printf("%s", dest);
	return (0);
}*/
