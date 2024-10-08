#include "pipex_bonus.h"

void	exit_args_error(int num)
{
	if (num == 1)
		perror("args");
	exit(EXIT_FAILURE);
}
