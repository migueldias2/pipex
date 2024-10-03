/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 23:28:09 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 17:43:35 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_counter(long n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		counter++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

static void	ft_converted(char *ptr, long n, size_t byte_count, size_t total)
{
	if (n == 0)
		ptr[byte_count - 1] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		ptr[byte_count - 1] = (n % 10) + '0';
		n = n / 10;
		byte_count--;
	}
	ptr[total - 1] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	byte_count;
	size_t	total;
	char	*ptr;

	byte_count = ft_counter(n);
	total = byte_count + 1;
	ptr = (char *)malloc((total) * sizeof(char));
	if (!ptr)
		return (NULL);
	ft_converted(ptr, n, byte_count, total);
	return (ptr);
}
/*int	main()
{
	char *ptr= ft_itoa(0);
	printf("%s", ptr);
}*/
/*int main()
{
	size_t	i = ft_counter(-2147483648);
	printf("%zu", i);
}*/
