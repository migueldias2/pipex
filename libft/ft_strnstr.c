/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:12:12 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/11 01:40:50 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (i < n && haystack[i] == needle[j] && needle[j])
			{
				i++;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i - j]);
		}
		else
			i++;
	}
	return (NULL);
}
/*int	main()
{
	char frase[] = "ola mu  mundo";
	char agulha[] = "mun";
	char *ptr = ft_strnstr(frase, agulha, 20);
	printf("%s", ptr);
}*/
