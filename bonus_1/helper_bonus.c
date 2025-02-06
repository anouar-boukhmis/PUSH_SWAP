/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:52:35 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/05 20:00:00 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstadd_back_bns(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast_bns(*lst)->next = new;
	else
		*lst = new;
}

void	read_and_stock(t_stack **a, t_stack **b, t_list **lst_operation)
{
	char	*operation;
	t_list	*new;

	operation = NULL;
	new = NULL;
	while (1)
	{
		operation = get_next_line(0);
		if (!operation)
			break ;
		if (!is_valable(operation))
		{
			free(operation);
			ft_lstclear_bns(lst_operation);
			errorexit(a, b);
		}
		new = ft_lstnew_bns(operation);
		ft_lstadd_back_bns(lst_operation, new);
	}
}
