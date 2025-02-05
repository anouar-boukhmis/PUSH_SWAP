/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:04:52 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/31 20:56:09 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_stack **a)
{
	*a = swap_stack(*a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	*b = swap_stack(*b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	*a = swap_stack(*a);
	*b = swap_stack(*b);
	write(1, "ss\n", 3);
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
