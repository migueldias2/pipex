/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perrors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:38:42 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/05 18:38:57 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_fork_error(int num)
{
	perror("fork");
	exit(num);
}

void	exit_pipe_error(int num)
{
	perror("pipe");
	exit(num);
}

void	exit_args_error(int num)
{
	perror("args");
	exit(num);
}

void	exit_open_error(int num)
{
	perror("open");
	exit(num);
}

void	exit_unlink_error(int num)
{
	perror("unlink");
	exit(num);
}
