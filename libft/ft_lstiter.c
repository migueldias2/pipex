/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:46:20 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/15 17:58:13 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		if (f)
			(*f)(lst->content);
		lst = lst->next;
	}
}
/*void	print_content(void *content)
{
	printf("%s\n", (char *)content);
}
int	main()
{
	t_list *head = NULL;
	t_list *node1 = ft_lstnew(ft_strdup("Apple"));
	t_list *node2 = ft_lstnew(ft_strdup("Banana"));
	t_list *node3 = ft_lstnew(ft_strdup("Orange"));
	head = node1;
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	ft_lstiter(head, print_content);
}*/
