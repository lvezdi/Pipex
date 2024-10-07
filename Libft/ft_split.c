/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 19:00:20 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/10/07 13:20:10 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*free_split(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

static size_t	ft_count_words(char *buffer, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == c)
			i++;
		else
		{
			words++;
			while (buffer[i] != c && buffer[i] != '\0')
				i++;
		}
	}
	return (words);
}

static void	ft_fill_array(char *array, char *buffer, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		array[i] = buffer[start];
		start++;
		i++;
	}
	array[i] = '\0';
}

static char	**ft_split_continuo(char *str, char **array, char c, int end)
{
	size_t	i;
	size_t	start;

	i = 0;
	array = ft_calloc((ft_count_words(str, c) + 1), sizeof(char *));
	if (array == NULL)
		return (NULL);
	while (str[end] != '\0')
	{
		if (str[end] == c)
			end++;
		else
		{
			start = end;
			while (str[end] != c && str[end] != '\0')
				end++;
			array[i] = malloc((end - start + 1) * sizeof(char));
			if (array[i] == NULL)
				return (free_split(array));
			ft_fill_array(array[i], str, start, end);
			i++;
		}
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	*str;
	char	**array;
	size_t	end;

	if (s == NULL)
		return (NULL);
	end = 0;
	str = (char *)s;
	array = NULL;
	return (ft_split_continuo(str, array, c, end));
}

/*int	main(void)
{
	char **f = ft_split(NULL, 'o');
	if (f)
	{
		for (int i = 0; f[i] != NULL; i++)
		{
    		printf("%s\n", f[i]);
		}
	}
    return (0);
}*/
