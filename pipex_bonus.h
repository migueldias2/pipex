/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:17:00 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/14 14:03:34 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define BUFFER_SIZE 1024

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
void	exit_read_error(int fd);
void	ft_free(char *list[]);
char	*get_env(char *env[]);
char	*get_path(char *cmd, char *env[]);
int		open_file(char *str, int num);
void	exit_path_error(void);
int		ft_words_empty(char *str[]);
void	input_checker(int argc, char *argv[], char *env[]);
void	handle_here_doc(int argc, int fd_out, char *argv[], int i);
void	here_doc(char *str);

#endif
