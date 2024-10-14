/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:17:11 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/14 14:11:15 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char *list[])
{
	int	i;

	i = 0;
	while (list[i] != NULL)
	{
		free(list[i]);
		i++;
	}
	free(list);
}

void	input_checker(int argc, char *argv[], char *env[])
{
	char	*path_env;

	if (argc < 5)
		exit_args_error(1);
	path_env = get_env(env);
	if (!path_env)
		exit_path_error();
	if (ft_words_empty(argv))
		exit_args_error(1);
}

void	handle_here_doc(int argc, int fd_out, char *argv[], int i)
{
	if (argc < 6)
		exit_args_error(1);
	i = 3;
	fd_out = open_file(argv[argc - 1], 2);
	here_doc(argv[2]);
}
