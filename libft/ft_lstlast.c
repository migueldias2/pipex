/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:13:24 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/16 12:37:13 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ptr;

	if (!lst)
		return (NULL);
	ptr = lst;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}
/*int	main()
{
	t_list *head = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));
	t_list	*lastnode;

	if (head == NULL || node2 == NULL || node3 == NULL)
		return (1);
	head->content = "head";
	head->next = node2;
	node2->content = "Node 2";
	node2->next = node3;
	node3->content = "Node 3";
	node3->next = NULL;
	lastnode = ft_lstlast(head);
	printf("%s\n", (char *)lastnode->content);
}*/
