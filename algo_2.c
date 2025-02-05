/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:17:10 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/01 19:52:21 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunck_size(int size)
{
	if (size > 100)
		return (34);
	return (16);
}

void	from_a_to_b(t_stack **a, t_stack **b, int i, int k)
{
	int		size_chunck;
	t_stack	*copy;

	size_chunck = chunck_size(ft_lstsize(*a));
	k = is_comb(*a, ft_lstsize(*a));
	i = 0;
	while (*a)
	{
		copy = *a;
		if (copy->index <= i)
		{
			pb(a, b);
			i++;
		}
		else if (copy->index <= (i + size_chunck))
		{
			pb(a, b);
			rb(b);
			i++;
		}
		else if (k == 1)
			rra(a);
		else
			ra(a);
	}
}

int	find_max(t_stack **a)
{
	t_stack	*copy;
	int		max;
	int		pos;

	copy = *a;
	max = 0;
	pos = 0;
	give_pos(&copy);
	while (copy)
	{
		if (copy ->index > max)
		{
			max = copy->index;
			pos = copy->pos;
		}
		copy = copy ->next;
	}
	return (pos);
}

void	from_b_to_a(t_stack **a, t_stack **b)
{
	int	size;
	int	pos;

	size = ft_lstsize(*b);
	while (size)
	{
		pos = find_max(b);
		if (pos <= size / 2)
		{
			while (pos--)
				rb(b);
		}
		else
		{
			while (pos++ != size)
				rrb(b);
		}
		pa(a, b);
		size--;
	}
}

void	sort_100_500(t_stack **a, t_stack **b)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	from_a_to_b(a, b, i, k);
	from_b_to_a(a, b);
}
