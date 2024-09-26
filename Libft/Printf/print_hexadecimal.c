/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexadecimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:11:50 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/07/05 10:35:14 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	number_hexadecimal_digit(size_t number)
{
	int	i;

	i = 0;
	while (number >= 16)
	{
		number = number / 16;
		i++;
	}
	i++;
	return (i);
}

int	print_hexadecimal_tolower(size_t number)
{
	char	*alphabet;
	int		position;
	int		i;

	alphabet = "0123456789abcdef";
	i = number_hexadecimal_digit(number);
	if (number <= 15)
	{
		position = number % 16;
		write (1, &alphabet[position], 1);
	}
	if (number >= 16)
	{
		print_hexadecimal_tolower(number / 16);
		position = number % 16;
		write (1, &alphabet[position], 1);
	}
	return (i);
}

int	print_hexadecimal_toupper(size_t number)
{
	char	*alphabet;
	int		position;
	int		i;

	alphabet = "0123456789ABCDEF";
	i = number_hexadecimal_digit(number);
	if (number <= 15)
	{
		position = number % 16;
		write (1, &alphabet[position], 1);
	}
	if (number >= 16)
	{
		print_hexadecimal_toupper(number / 16);
		position = number % 16;
		write (1, &alphabet[position], 1);
	}
	return (i);
}

int	print_pointer(size_t ptr)
{
	int		i;

	i = 0;
	if (ptr == 0)
		i += print_str("(nil)");
	else
	{
		i += print_str("0x");
		i += print_hexadecimal_tolower(ptr);
	}
	return (i);
}

/*#include <stdio.h>
int main()
{
	char *Madrid = "42";
	printf("Number of characters: %i\n", ft_printf("Content: %x\n", 42));
	printf("Number of characters: %i\n", printf("Content: %x\n", 42));
	printf("Number of characters: %i\n", ft_printf("Content: %X\n", 42));
	printf("Number of characters: %i\n", printf("Content: %X\n", 42));
	printf("Number of characters: %i\n", ft_printf("Content: %p\n", Madrid));
	printf("Number of characters: %i\n", printf("Content: %p\n", Madrid));
	return (0);
}*/
