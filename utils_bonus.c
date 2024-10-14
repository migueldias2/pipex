/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:17:06 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/11 18:24:07 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_path_error(void)
{
	perror("commands not found");
	exit(EXIT_FAILURE);
}

int	ft_words_empty(char *str[])
{
	int	i;
	int	j;
	int	empty;

	i = 1;
	while (str[i])
	{
		j = 0;
		empty = 1;
		if (str[i][0] == '\0')
			return (1);
		while (str[i][j] != '\0')
		{
			if (str[i][j] != ' ' && str[i][j] != '\t')
			{
				empty = 0;
				break ;
			}
			j++;
		}
		if (empty == 1)
			return (1);
		i++;
	}
	return (0);
}

int	open_file(char *str, int num)
{
	int	fd;

	fd = 9;
	if (num == 2)
		fd = open(str, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (num == 1)
		fd = open(str, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (num == 0)
		fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		exit_open_error(1);
	return (fd);
}

char	*get_env(char *env[])
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' \
			&& env[i][2] == 'T' && env[i][3] == 'H')
			return (env[i] + 5);
	}
	return (NULL);
}

char	*get_path(char *cmd, char *env[])
{
	int		i;
	char	*exec;
	char	**allpath;
	char	*path_part;
	char	*env_path;

	env_path = get_env(env);
	if (!env_path)
		return (cmd);
	i = -1;
	allpath = ft_split(get_env(env), ':');
	if (!allpath)
		return (cmd);
	while (allpath[++i])
	{
		path_part = ft_strjoin(allpath[i], "/");
		exec = ft_strjoin(path_part, cmd);
		free(path_part);
		if (access(exec, F_OK | X_OK) == 0)
			return (exec);
		free(exec);
	}
	ft_free(allpath);
	return (cmd);
}
