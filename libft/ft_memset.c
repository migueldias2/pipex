/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 14:50:53 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/09 18:40:41 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *)ptr;
	if (!ptr)
		return (ptr);
	while (i < num)
	{
		p[i] = (unsigned char)value;
		i++;
	}
	return (p);
}
