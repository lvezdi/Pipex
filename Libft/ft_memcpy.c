/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 15:01:46 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:32:54 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	i = 0;
	if (!d && !s)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
/*int main(void)
{
    char    s[] = "42 Madrid";
    char    d[10];
	size_t	len = 10;
   
    printf("Original text: %s\n", s);
    ft_memcpy(d, s, len);
    printf("Final text: %s\n", d);
    return (0);
}*/
