/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 13:04:13 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 13:13:01 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*ptr;
	int		counter;

	counter = 0;
	ptr = lst;
	while (ptr != NULL)
	{
		counter++;
		ptr = ptr->next;
	}
	return (counter);
}
/*int	main()
{
	int	size;
	t_list *head = malloc(sizeof(t_list));
	t_list *node2 = malloc(sizeof(t_list));
	t_list *node3 = malloc(sizeof(t_list));

	if (head == NULL || node2 == NULL || node3 == NULL)
		return (1);
	head->content = "head";
	head->next = node2;
	node2->content = "Node 2";
	node2->next = node3;
	node3->content = "Node 3";
	node3->next = NULL;
	size = ft_lstsize(head);
	printf("%d\n", size);
}*/
