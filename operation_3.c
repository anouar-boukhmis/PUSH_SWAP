/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:55:48 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/31 20:58:02 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack **a, t_stack **b)
{
	*a = rotatx(*a);
	*b = rotatx(*b);
	write(1, "rr\n", 3);
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

void	rra(t_stack **a)
{
	*a = rrx(*a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	*b = rrx(*b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	*a = rrx(*a);
	*b = rrx(*b);
	write(1, "rrr\n", 4);
}
