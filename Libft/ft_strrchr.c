/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 12:31:41 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/07/17 15:36:04 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (unsigned char) c)
			return ((char *) &s[i]);
		i--;
	}
	return (0);
}
/*int	main(void)
{
	const char	s[] = "42 Madrid";
	int	c = 'r';
	char	*result;
	result = ft_strrchr(s, c);
	printf("Position: %ld\n",  result - s);
	return (0);
}*/
