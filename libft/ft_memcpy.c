/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:17:01 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/09 18:46:16 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char		*temp_dest;
	size_t		i;

	temp_dest = dest;
	i = 0;
	if (!dest || !src)
		return (dest);
	while (i < num)
	{
		temp_dest[i] = ((const char *)src)[i];
		i++;
	}
	return (temp_dest);
}
