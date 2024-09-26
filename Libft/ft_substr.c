/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:56:50 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:40:05 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc(len + 1);
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	return (substr);
}

/*int	main(void)
{
	char *s = "Madrid 42";
	int len = 2;
	int start = 7;
	char	*str = ft_substr(s, start, len);
	//printf("Reques: Len: %d \nStart: %d \nString: %s \nResponse: %s,
		//Expected: 42",len, start, s, str);
	return (0);	
}*/
