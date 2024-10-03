/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 22:43:40 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/12 22:49:35 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
/*int	main()
{
	char *message = "Hello, world!";
	ft_putstr_fd(message, STDOUT_FILENO);
	ft_putstr_fd(message, STDERR_FILENO);
	return (0);
}*/
