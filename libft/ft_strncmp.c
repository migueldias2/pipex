/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:54:16 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 21:42:41 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while (n > 0)
	{
		c1 = (unsigned char)*s1;
		c2 = (unsigned char)*s2;
		if (c1 != c2)
			return ((int)c1 - (int)c2);
		if (c1 == '\0')
			break ;
		n--;
		s1++;
		s2++;
	}
	return (0);
}
/*int main()
{
	const char *str1 = "hello";
	const char *str2 = "hell";
	int result = ft_strncmp(str1, str2, 5);
	printf("%d", result);
}*/
