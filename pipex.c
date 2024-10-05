/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 18:38:45 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/05 18:41:13 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *cmd, char *env[])
{
	char	**cmd_list;
	char	*path;

	cmd_list = ft_split(cmd, ' ');
	path = get_path(cmd_list[0], env);
	if (execve(path, cmd_list, env) == -1)
	{
		perror("execve");
		ft_free(cmd_list);
		exit(1);
	}
}

void	handle_child2(int *pipe_fd, char *argv[], char *env[])
{
	int	outfile;

	if (access(argv[4], F_OK) == 0)
	{
		if (unlink(argv[4]) == -1)
			exit_unlink_error(1);
	}
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		exit_open_error(1);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	close(outfile);
	exec(argv[3], env);
}

void	handle_child1(int *pipe_fd, char *argv[], char *env[])
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		exit_open_error(1);
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
	pid_t	pid2;

	if (argc != 5)
		exit_args_error(1);
	if (pipe(pipe_fd) == -1)
		exit_pipe_error(1);
	pid1 = fork();
	if (pid1 == -1)
		exit_fork_error(1);
	else if (pid1 == 0)
		handle_child1(pipe_fd, argv, env);
	pid2 = fork();
	if (pid2 == -1)
		exit_fork_error(1);
	else if (pid2 == 0)
		handle_child2(pipe_fd, argv, env);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
