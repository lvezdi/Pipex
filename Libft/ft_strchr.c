/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 10:29:20 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:04:11 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char) c)
			return ((char *)&s[i]);
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*int	main(void)
{
	const char	*s = "42 Madrid";
	int	c = 'a';
	char	*result;
	result = ft_strchr(s, c);
	printf("Position: %ld\n", result - s);
	return (0);
}*/
