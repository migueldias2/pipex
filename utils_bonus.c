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
