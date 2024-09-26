/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 11:10:22 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:30:48 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cc;
	size_t			i;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*str == cc)
			return (str);
		str++;
		i++;
	}
	return (0);
}
/*int	main(void)
{
	const char	str[] = "Madrid.42";
	const char	ch = '.';
	size_t	len = 9;
	void	*ptr;
	
	ptr = ft_memchr(str, ch, len);
	printf("String after: %s", ptr);
	return (0);	
}*/
