/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:49:50 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/09 18:37:57 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*temp_dest;
	size_t		i;

	temp_dest = dest;
	if (!dest && !src)
		return (dest);
	if (dest > src && (dest - n < src))
	{
		i = n;
		while (i)
		{
			temp_dest[i - 1] = ((char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			temp_dest[i] = ((char *)src)[i];
			i++;
		}
	}
	return (temp_dest);
}
/*int	main()
{
	char frase[]="ola mundo";
	char *ptr = ft_memmove(frase+2, frase, 3);
	printf("%s", ptr);
}*/
