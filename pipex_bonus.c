#include "pipex_bonus.h"

void	here_doc(int argc, char *argv[])
{
	int		pipe_fd[2];
	char	*string;




}

int	main(int argc, char *argv[], char *env[])
{
	int	i;
	int	fd_in;
	int	fd_out;

	if (argc < 5)
		exit_args_error(1);
	if (ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc < 6)
			exit_args_error(1);
		i = 3;
		fd_out = open_file(argv[argc - 1], 2);
		here_doc(argc, argv);
	}
}
