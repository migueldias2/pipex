/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarepa- <mcarepa-@student.42lisboa.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 18:00:16 by mcarepa-          #+#    #+#             */
/*   Updated: 2024/04/16 14:49:34 by mcarepa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static t_list	*lst_new(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

static void	lst_clear(t_list **lst, void (*del)(void *))
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

static void	lstadd_back(t_list **lst, t_list *new)
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

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = lst_new(f(lst->content));
		if (!new_node)
		{
			lst_clear(&new_list, (*del));
			return (NULL);
		}
		lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

/*void	*extract_two(void *content)
{
	char *str = (char *)content;
	if (!str)
		return NULL;
	char *new_str = (char *)malloc(3 * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[0] = str[0];
	new_str[1] = str[1];
	new_st[2] = '\0';
	return (new_str);
}
void	del_string(void *content)
{
	if (content)
		free(content);
}
int	main()
{
	t_list *head = NULL;
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("apple")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("banana")));
	t_list *new_list = ft_lstmap(head, extract_two, del_string);
	t_list *current = new_list;
	while (current != NULL)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}

}*/
