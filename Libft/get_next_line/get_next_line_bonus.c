/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:38:04 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/07/05 11:00:59 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL && s2 == NULL)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
			* sizeof(char));
	if (str == NULL)
		return (free(s1), NULL);
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
	free(s1);
	return (str);
}

static char	*take_after_new_line(char *temp)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (!temp[i])
	{
		free(temp);
		return (NULL);
	}
	dest = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
	if (!dest)
		return (free(temp), NULL);
	j = 0;
	while (temp[i])
		dest[j++] = temp[++i];
	dest[j] = '\0';
	free(temp);
	return (dest);
}

static char	*take_until_new_line(char *str)
{
	int		i;
	char	*dest;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str && str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		dest[i++] = '\n';
	dest[i] = '\0';
	return (dest);
}

static char	*read_until_new_line(int fd, char **str)
{
	char	*buff;
	int		bytes_read;

	if (!*str)
	{
		*str = malloc(1 * sizeof(char));
		*str[0] = '\0';
	}
	if (!*str)
		return (NULL);
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(*str), NULL);
	bytes_read = 1;
	while (!ft_strchr(*str, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buff), free(*str), NULL);
		buff[bytes_read] = '\0';
		*str = ft_strjoin_gnl(*str, buff);
		if (!*str)
			return (free(buff), NULL);
	}
	return (free(buff), *str);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = read_until_new_line(fd, &str[fd]);
	if (!str[fd])
		return (0);
	line = take_until_new_line(str[fd]);
	if (!line)
	{
		free(line);
		free(str[fd]);
		str[fd] = NULL;
		return (NULL);
	}
	str[fd] = take_after_new_line(str[fd]);
	return (line);
}

/*int main(int argc, char **argv)
{
    int fd;
    char    *line;
    int l;
    for (int i = 1; i < argc; i++)
    {
        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
            return (0);
        l = 1;
        printf("Get_Next_Line de: %s \n", argv[i]);
        while (1)
        {
            line = get_next_line(fd);
            if (!line)
            {
                printf("\nFin del fichero\n");
                break;
            }
            printf("[%d]: %s", l, line);
            l++;
        }
        close(fd);
    }
    return (0);
}*/
