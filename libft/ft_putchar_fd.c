/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 17:07:54 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/12 22:41:57 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*int	main()
{
	char	ch = 'A';
	ft_putchar_fd(ch, STDOUT_FILENO );
	ft_putchar_fd(ch, STDIN_FILENO);
	ft_putchar_fd(ch, STDERR_FILENO);
}*/
