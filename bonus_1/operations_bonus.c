/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:08:17 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/26 19:25:40 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa_bonus(t_stack **a)
{
	*a = swap_stack(*a);
}

void	ss_bonus(t_stack **a, t_stack **b)
{
	sa_bonus(a);
	sa_bonus(b);
}

void	pa_bonus(t_stack **a, t_stack **b)
{
	pushx(a, b);
}

void	ra_bonus(t_stack **a)
{
	*a = rotatx(*a);
}

void	rr_bonus(t_stack **a, t_stack **b)
{
	ra_bonus(a);
	ra_bonus(b);
}
