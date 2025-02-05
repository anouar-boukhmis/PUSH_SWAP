/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:55:32 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/25 17:30:34 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	pushx(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	pushx(b, a);
	write(1, "pb\n", 3);
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

void	ra(t_stack **a)
{
	*a = rotatx(*a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (!b || !*b)
		return ;
	*b = rotatx(*b);
	write(1, "rb\n", 3);
}
