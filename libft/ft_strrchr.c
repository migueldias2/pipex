/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:41:02 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 21:30:27 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	char	ch;

	ch = (char)c;
	ptr = NULL;
	while (*str)
	{
		if (*str == ch)
			ptr = (char *)str;
		str++;
	}
	if (ch == '\0')
		return ((char *)str);
	return (ptr);
}
/*int main()
{
    const char frase[] = "hello world";
    char *last_occurrence = ft_strrchr(frase, 'l');
    printf("%s\n", last_occurrence);
    return 0;
}*/
