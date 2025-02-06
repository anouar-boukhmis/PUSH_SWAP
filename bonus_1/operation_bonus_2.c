/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:33:29 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/26 19:27:37 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rra_bonus(t_stack **a)
{
	*a = rrx(*a);
}

void	rrr_bonus(t_stack **a, t_stack **b)
{
	rra_bonus(a);
	rra_bonus(b);
}

void	free_stack(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
}

void	errorexit(t_stack **a, t_stack **b)
{
	write(2, "Error\n", 7);
	free_stack(a, b);
	exit(0);
}
