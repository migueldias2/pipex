/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:29:12 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/16 19:15:25 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!del || !lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
/*void	del_string(void *content)
{
	if (content)
		free(content);
}
int	main()
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return (1);
	node->content = (void *)ft_strdup("Hello World!");
	printf("%s\n", (char *)node->content);
	ft_lstdelone(node, del_string);
	printf("%s\n", (char *)node->content);
}*/
