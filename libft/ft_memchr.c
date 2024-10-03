/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:21:05 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/10 21:58:38 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	const unsigned char	*srh;

	srh = ptr;
	while (num > 0)
	{
		if (*srh == (unsigned char)value)
			return ((void *)(srh));
		srh++;
		num--;
	}
	return (NULL);
}
/*int	main()
{
	char	str[] = "Ola mundo";
	char	*pointer = ft_memchr(str, 'n', 7);
	printf("%s", pointer);
}*/
