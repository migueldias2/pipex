/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:16:56 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/10/14 14:10:06 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	here_doc(char *str)
{
	char	buffer[BUFFER_SIZE];
	int		fd;
	ssize_t	bytes_read;

	fd = open("temp.txt", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)
		exit_open_error(1);
	while (1)
	{
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE - 1);
		if (bytes_read < 0)
			exit_read_error(fd);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (ft_strncmp(buffer, str, ft_strlen(str)) == 0 && \
	(buffer[ft_strlen(str)] == '\n' || buffer[ft_strlen(str)] == '\0'))
			break ;
		write(fd, buffer, bytes_read);
	}
	close(fd);
	fd = open("temp.txt", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	unlink("temp.txt");
	close(fd);
}

void	do_last_pipe(char *cmd, char *env[], int fd_out)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_fork_error(1);
	if (pid == 0)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
		exec(cmd, env);
	}
	else
	{
		close(fd_out);
	}
}

void	do_pipe(char *cmd, char *env[], int fd_out)
{
	pid_t	pid;
	int		pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		exit_pipe_error(1);
	pid = fork();
	if (pid == -1)
		exit_fork_error(1);
	if (pid == 0)
	{
		close(fd_out);
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		exec(cmd, env);
	}
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
	}
}

int	main(int argc, char *argv[], char *env[])
{
	int	i;
	int	fd_in;
	int	fd_out;

	i = 0;
	fd_out = 10;
	input_checker(argc, argv, env);
	if (ft_strcmp(argv[1], "here_doc") == 0)
		handle_here_doc(argc, fd_out, argv, i);
	else
	{
		i = 2;
		fd_in = open_file(argv[1], 0);
		fd_out = open_file(argv[argc - 1], 1);
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], env, fd_out);
	do_last_pipe(argv[i], env, fd_out);
	while ((wait(NULL)) > 0)
		;
}
