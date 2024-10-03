/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:57:14 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/11 01:42:07 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (!n)
		return (i);
	while (n > 1 && *src)
	{
		*dest++ = *src++;
		n--;
	}
	*dest = '\0';
	return (i);
}
