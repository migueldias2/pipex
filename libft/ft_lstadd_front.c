/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 12:07:16 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 13:03:32 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*int	main()
{
	t_list	*head;
	t_list	*node2;
	t_list *current;

	head = (t_list *)malloc(sizeof(t_list));
	node2 = (t_list *)malloc(sizeof(t_list));
	if (!head || !node2)
		return (1);
	head->content = "Head";
	head->next = NULL;
	node2->content = "Node 2";
	node2->next = NULL;
	ft_lstadd_front(&head, node2);
	current = head;
	while (current != NULL)
	{
		printf("%s; ", (char *)current->content);
		current = current->next;
	}
}*/
