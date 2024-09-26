/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:15:01 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/07/05 10:35:35 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	print_format(char specifier, va_list arg_pointer)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(arg_pointer, int));
	else if (specifier == 's')
		count += print_str(va_arg(arg_pointer, char *));
	else if (specifier == 'p')
		count += print_pointer(va_arg(arg_pointer, size_t));
	else if ((specifier == 'd') || (specifier == 'i'))
		count += print_int(va_arg(arg_pointer, int));
	else if (specifier == 'u')
		count += print_unsigned_int(va_arg(arg_pointer, unsigned int));
	else if (specifier == 'x')
		count += print_hexadecimal_tolower(va_arg(arg_pointer, unsigned int));
	else if (specifier == 'X')
		count += print_hexadecimal_toupper(va_arg(arg_pointer, unsigned int));
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg_pointer;
	int		count;

	va_start(arg_pointer, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*(++format), arg_pointer);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(arg_pointer);
	return (count);
}
