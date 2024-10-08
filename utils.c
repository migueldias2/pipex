/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:38:50 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/08 14:10:45 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
