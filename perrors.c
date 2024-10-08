/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perrors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:38:42 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/07 17:37:19 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_fork_error(int num)
{
	if (num == 1)
		perror("fork");
	exit(EXIT_FAILURE);
}

void	exit_pipe_error(int num)
{
	if (num == 1)
		perror("pipe");
	exit(EXIT_FAILURE);
}

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

void	exit_unlink_error(int num)
{
	if (num == 1)
		perror("unlink");
	exit(EXIT_FAILURE);
}
