/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 11:13:13 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/10/07 13:21:21 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
/*int	main(void)
{
	int	tolower = 'F';
	int	test;
	test = ft_tolower(tolower);
	printf("%d", test);
	return (0);
}*/
