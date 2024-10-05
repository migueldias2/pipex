/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:07:09 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/05 18:38:59 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>

void	exit_fork_error(int num);
void	exit_pipe_error(int num);
void	exit_args_error(int num);
void	exit_open_error(int num);
void	exit_unlink_error(int num);
void	ft_free(char *list[]);
char	*get_env(char *env[]);
char	*get_path(char *cmd, char *env[]);

#endif
