/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:00:22 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/11 16:33:04 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num_elements, size_t element_size)
{
	void	*ptr;
	size_t	total;

	total = num_elements * element_size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total);
	return (ptr);
}
/*int	main()
{
	int *array1 = ft_calloc(4, sizeof(int));
	printf("%d, %d, %d, %d", array1[0], array1[1], array1[2], array1[3]);
}*/
