/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:59:22 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/10 23:18:57 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	i = 0;
	s1 = (const unsigned char *)ptr1;
	s2 = (const unsigned char *)ptr2;
	while (num > 0)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
		num--;
	}
	return (0);
}
/*int	main()
{
	int	a = ft_memcmp("ola", "ola", 5);
	int	b = ft_memcmp("ola", "adeus", 10);
	int arr1[] = {1, 2, 3};
    	int arr2[] = {1, 2, 4};
    	int c = ft_memcmp(arr1, arr2, 3 * sizeof(int));
	printf("%d\n", a);
        printf("%d\n", b);
    	printf("%d\n", c);

    return 0;
}*/
