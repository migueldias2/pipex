/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:04:49 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 17:33:14 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next;

	current = *lst;
	while (current != NULL)
	{
		next = current->next;
		if (del)
			(*del)(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}
/*void del_string(void *content)
{
	if (content)
		free(content);
}
int	main()
{
	t_list *node1 = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));
	if (!node1 || !node2 || !node3)
		return 1;
	node1->content = ft_strdup("Node 1");
	node1->next = node2;
	node2->content = ft_strdup("Node 2");
	node2->next = node3;
	node3->content = ft_strdup("Node 3");
	node3->next = NULL;
	t_list *current = node1;
	while (current != NULL)
	{
		printf("%s ", (char *)current->content);
		current = current->next;
	}
	ft_lstclear(&node1, del_string);
	while (current != NULL)
        {
                printf("%s ", (char *)current->content);
                current = current->next;
        }
}*/
