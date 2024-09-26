/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvez-dia <lvez-dia@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:13:54 by lvez-dia          #+#    #+#             */
/*   Updated: 2024/05/03 13:25:42 by lvez-dia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*pointer;

	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	total_size = count * size;
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	ft_memset(pointer, 0, total_size);
	return (pointer);
}
/*int	main(void)
{
	int	*ptr;
	ptr = ft_calloc(20, sizeof(int));
	*ptr = 20;
	printf("Allocated memory address: %p\n", ptr);
	printf("value of the variable: %d", *ptr);
	return (0);
}*/
