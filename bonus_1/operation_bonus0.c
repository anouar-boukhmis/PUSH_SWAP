/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 18:31:21 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/30 22:50:56 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

t_stack	*swap_stack(t_stack *a)
{
	t_stack	*b;

	if (!a || !a -> next)
		return (a);
	b = a -> next;
	a -> next = b -> next;
	b -> next = a;
	return (b);
}

t_stack	*pushx(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!b || !*b)
		return (NULL);
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	return (*a);
}

t_stack	*rotatx(t_stack *a)
{
	t_stack	*l;
	t_stack	*k;

	if (!a || !a->next)
		return (a);
	l = a;
	l = l->next;
	k = ft_lstlast(l);
	k->next = a;
	a->next = NULL;
	return (l);
}

t_stack	*rrx(t_stack *a)
{
	t_stack	*l;
	t_stack	*k;

	if (!a || !a->next)
		return (a);
	k = a;
	while (k->next->next)
		k = k->next;
	l = k->next;
	k->next = NULL;
	l->next = a;
	return (l);
}
