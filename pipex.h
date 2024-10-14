/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:07:09 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/11 18:36:19 by mcarepa-         ###   ########.fr       */
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
void	exit_path_error(void);
void	exit_args_error(int num);
void	exit_open_error(int *pipe_fd);
void	exit_unlink_error(int num);
void	ft_free(char *list[]);
char	*get_env(char *env[]);
char	*get_path(char *cmd, char *env[]);
void	finish_main(int *pipe_fd);

#endif
