/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:58:11 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/07/05 10:35:23 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putnbr(long n)
{
	if (n < 0)
	{
		print_char('-');
		n = n * (-1);
	}
	if (n < 10)
		print_char(n % 10 + 48);
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		print_char(n % 10 + 48);
	}
}

int	print_int(int number)
{
	int	i;

	i = 0;
	ft_putnbr(number);
	if (number < 0)
		i++;
	while (number >= 10 || number <= -10)
	{
		number = number / 10;
		i++;
	}
	i++;
	return (i);
}

int	print_unsigned_int(unsigned int number)
{
	int	i;

	i = 0;
	ft_putnbr(number);
	while (number >= 10)
	{
		number = number / 10;
		i++;
	}
	i++;
	return (i);
}

/*#include <stdio.h>
#include <limits.h>
int main()
{
	char	*hola = NULL;
	int		nbr = INT_MIN;
	ft_printf("%d\n", nbr);
	printf("Number of characters: %i\n", ft_printf("%d\n", nbr));
	printf("Number of characters: %i\n", printf("%d\n", nbr));
	printf("Number of characters: %i\n", ft_printf("Content: %i\n", nbr));
	printf("Number of characters: %i\n", printf("Content: %i\n", nbr));
	printf("Number of characters: %i\n", ft_printf("Content: %u\n", nbr));
	printf("Number of characters: %i\n", printf("Content: %u\n", nbr));
	printf("Number of characters: %i\n", ft_printf("Content: %%\n"));
	printf("Number of characters: %i\n", printf("Content: %%\n"));
	
    return (0);
}*/
