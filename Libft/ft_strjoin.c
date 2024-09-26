/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:59:50 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:36:10 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 != NULL && s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
/*int	main(void)
{
	char	str1[] = "42 ";
	char	str2[] = "Madrid";
	char	*result;

	result = ft_strjoin(str1, str2);
	printf("Result: %s \n", result);
	free(result)
	return (0);
}*/
