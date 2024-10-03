/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:00:22 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/17 16:21:54 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (set[j])
	{
		if (s1[i] == set[j])
		{
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	j;
	size_t	len_s1;

	len_s1 = ft_strlen(s1) - 1;
	j = 0;
	while (set[j])
	{
		if (s1[len_s1] == set[j])
		{
			len_s1--;
			j = 0;
		}
		else
			j++;
	}
	return (len_s1 + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	total;
	size_t	i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (end > start)
		total = end - start;
	else
		total = 0;
	ptr = (char *)malloc((total + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < total)
	{
		ptr[i++] = s1[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}
/*int	main()
{
	char *trimmed = ft_strtrim("nl,  ola mundo  l,  ", "n 	l,");
	printf("%s", trimmed);
}*/
