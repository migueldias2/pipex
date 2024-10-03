/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 14:18:49 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/05/23 16:15:33 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	len_s1;
	size_t	len_s2;
	size_t	i;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	string = (char *)malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (!string)
		return (NULL);
	while (*s1)
		string[i++] = *s1++;
	while (*s2)
		string[i++] = *s2++;
	string[i] = '\0';
	return (string);
}
