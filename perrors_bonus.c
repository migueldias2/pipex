/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perrors_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:16:49 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/11 16:16:50 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_args_error(int num)
{
	if (num == 1)
		perror("args");
	exit(EXIT_FAILURE);
}

void	exit_open_error(int num)
{
	if (num == 1)
		perror("open");
	exit(EXIT_FAILURE);
}

void	exit_read_error(int fd)
{
	perror("read");
	close(fd);
	exit(EXIT_FAILURE);
}

void	exit_pipe_error(int num)
{
	if (num == 1)
		perror("pipe");
	exit(EXIT_FAILURE);
}

void	exit_fork_error(int num)
{
	if (num == 1)
		perror("fork");
	exit(EXIT_FAILURE);
}
