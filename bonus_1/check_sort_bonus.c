/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:44:56 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/05 19:58:35 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sorted_stack(t_stack *a)
{
	t_stack	*copy;

	copy = a;
	while (copy && copy->next)
	{
		if (copy->index > copy->next->index)
			return (0);
		copy = copy->next;
	}
	return (1);
}

void	give_index(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *a;
	while (temp1)
	{
		temp1->index = 0;
		temp2 = *a;
		while (temp2)
		{
			if (temp1->value > temp2->value)
				temp1->index++;
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}

t_list	*ft_lstnew_bns(char *str)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	else
	{
		new_node->str = str;
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	new_node->next = NULL;
	return (new_node);
}

void	ft_lstclear_bns(t_list **lst)
{
	t_list	*temp;
	t_list	*copy;

	if (!lst)
		return ;
	copy = *lst;
	while (copy)
	{
		temp = copy->next;
		free(copy->str);
		free(copy);
		copy = temp;
	}
	*lst = NULL;
}

t_list	*ft_lstlast_bns(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
