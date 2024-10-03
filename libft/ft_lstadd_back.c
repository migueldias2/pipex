/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:23:50 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 14:48:05 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
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
	ft_lstadd_back(&head, node2);
	current = head;
	while (current->next != NULL)
		current = current->next;
	printf("%s; ", (char *)current->content);
}*/
