/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 18:19:51 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:00:19 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_fill_array(char *str, int num, int len)
{
	str[len--] = '\0';
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *) ft_calloc ((len + 1), sizeof (char));
	if (str == NULL)
		return (NULL);
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		num = n * -1;
		str[0] = '-';
	}
	else
		num = n;
	return (ft_fill_array(str, num, len));
} 
/*int	main(void)
{
	int	num = -638;

	printf("Result: %s", ft_itoa(num));
	return (0);
}*/
