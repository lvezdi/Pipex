/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 13:33:45 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:36:38 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dstsize && dst[i] != '\0')
		i++;
	while ((i + j + 1) < dstsize && src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != dstsize)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*int main (void)
{
    char src[] = "Madrid";
	char dest[50] = "42 ";
	size_t len;

	len = ft_strlcat(dest, src, sizeof(dest) - 1);
	printf("Size: %lu \n", sizeof(dest) - 1);
	printf("Destination: %s \n", dest);
	printf("Length: %zu\n", len);
    return 0;
}*/
