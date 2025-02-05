/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:50:16 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/25 17:21:26 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sortfour(t_stack **a, t_stack **b)
{
	while ((*a)->index != 0)
	{
		if ((*a)-> next->next->next->index == 0)
			rra(a);
		else
			ra(a);
	}
	pb(a, b);
}

void	sort_5_4(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) == 5)
		sortfive(a, b);
	else
		sortfour(a, b);
	sort_3(a);
	if (ft_lstsize(*b) == 2)
		pa(a, b);
	pa(a, b);
}
