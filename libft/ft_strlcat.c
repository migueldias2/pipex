/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 21:08:23 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 21:09:26 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			dest_len;
	size_t			src_len;
	size_t			available_space;
	char			*dest_end;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dest_len)
		return (src_len + size);
	available_space = size - dest_len - 1;
	dest_end = dest + dest_len;
	while (*src && available_space > 0)
	{
		*dest_end++ = *src++;
		available_space--;
	}
	*dest_end = '\0';
	return (dest_len + src_len);
}
/*int	main()
{
	char frase[25] = "ola mundo";
	printf("%s", frase);
	int j = ft_strlcat(frase, "tudo bem", 25);
	printf("%d", j);
	printf("%s", frase);
}*/
