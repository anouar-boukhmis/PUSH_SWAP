/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:44:56 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/30 22:51:11 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	check_sorted_stack(t_stack *a)
{
	t_stack	*copy;

	copy = a;
	while (copy->next)
	{
		if (copy->index > copy->next->index)
			return (0);
		copy = copy->next;
	}
	return (1);
}

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
