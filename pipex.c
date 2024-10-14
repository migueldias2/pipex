/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:38:45 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/14 11:11:24 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	exec(char *cmd, char *env[])
{
	char	**cmd_list;
	char	*path;

	cmd_list = ft_split(cmd, ' ');
	if (!cmd_list)
	{
		perror("Failed to split command");
		exit(EXIT_FAILURE);
	}
	path = get_path(cmd_list[0], env);
	if (execve(path, cmd_list, env) == -1)
	{
		perror("execve");
		ft_free(cmd_list);
		exit(EXIT_FAILURE);
	}
}

void	handle_child2(int *pipe_fd, char *argv[], char *env[])
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		exit_open_error(pipe_fd);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(outfile);
	exec(argv[3], env);
}

void	handle_child1(int *pipe_fd, char *argv[], char *env[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		exit_open_error(pipe_fd);
	dup2(infile, STDIN_FILENO);
	dup2(pipe_fd[1], STDOUT_FILENO);
	close(infile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	exec(argv[2], env);
}

int	main(int argc, char *argv[], char *env[])
{
	int		pipe_fd[2];
	pid_t	pid1;
	char	*path_env;

	if (argc != 5)
		exit_args_error(1);
	if (ft_words_empty(argv) == 1)
		exit_args_error(1);
	path_env = get_env(env);
	if (!path_env)
		exit_path_error();
	if (pipe(pipe_fd) == -1)
		exit_pipe_error(1);
	pid1 = fork();
	if (pid1 == -1)
		exit_fork_error(1);
	else if (pid1 == 0)
		handle_child1(pipe_fd, argv, env);
	pid1 = fork();
	if (pid1 == -1)
		exit_fork_error(1);
	else if (pid1 == 0)
		handle_child2(pipe_fd, argv, env);
	finish_main(pipe_fd);
	return (0);
}
