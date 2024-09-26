/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:16:53 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/07/17 15:33:40 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!needle[0])
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && len > (i + j) && haystack[i + j]
			&& needle[j])
			j++;
		if (!needle[j])
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
/*int	main(void)
{
	const char	largestring[] = "Welcome to 42 Madrid";
	const char	smallstring[] = "42";
	size_t	len = 20;
	char	*ptr;

	ptr = ft_strnstr(largestring, smallstring, len);
	printf("%s", ptr);
	return (0);
}*/
