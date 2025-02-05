/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:53:46 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/01 13:10:15 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	give_pos(t_stack **stack)
{
	t_stack	*copy;
	int		i;

	i = 0;
	copy = *stack;
	while (copy)
	{
		copy->pos = i;
		i++;
		copy = copy->next;
	}
}

int	check_sorted_stack(t_stack *a)
{
	t_stack	*copy;

	if (!a)
		exit(0);
	copy = a;
	while (copy->next)
	{
		if (copy->index > copy->next->index)
			return (0);
		copy = copy->next;
	}
	return (1);
}

void	sort_3(t_stack **a)
{
	if (!a || ! (*a)->next)
		return ;
	if (!(*a)->next->next)
	{
		if ((*a)->index > (*a)->next->index)
			sa(a);
		return ;
	}
	if ((*a)->index > (*a)->next->index
		&& (*a)->index > (*a)->next->next->index)
		ra(a);
	else if ((*a)->next->index > (*a)->index
		&& (*a)->next->index > (*a)->next->next->index)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sortfive(t_stack **a, t_stack **b)
{
	while ((*a)->index != 0)
	{
		if ((*a)-> next->next->next->next->index == 0)
			rra(a);
		else if ((*a)-> next->next->next->index == 0)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
	while ((*a)->index != 1)
	{
		if ((*a)-> next->next->next->index == 1)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
}
