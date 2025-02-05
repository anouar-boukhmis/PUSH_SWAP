/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmbine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:25:36 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/25 17:26:11 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_comb(t_stack *a, int size)
{
	int	diff;
	int	count;

	count = 0;
	while (a && a->next)
	{
		diff = a->index - a->next->index;
		if (diff == 2 || diff == 3 || diff == 4)
			count++;
		a = a->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}
