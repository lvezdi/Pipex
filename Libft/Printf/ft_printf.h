/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:13:01 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/06/04 11:58:38 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *format, ...);
int		print_char(char c);
int		print_str(char *s);
int		print_int(int number);
int		print_hexadecimal_tolower(size_t number);
int		print_hexadecimal_toupper(size_t number);
int		print_unsigned_int(unsigned int number);
int		print_pointer(size_t ptr);

#endif
