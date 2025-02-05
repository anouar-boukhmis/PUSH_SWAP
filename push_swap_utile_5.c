/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:35:04 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/05 14:48:44 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeee(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

void	free_ever(char *ptr, char **sp_str, t_stack **a, t_stack **b)
{
	free(ptr);
	free_error(sp_str, a, b);
}

int	signe_o(char c, int *i)
{
	int	sign;

	sign = 1;
	if (c == '-' || c == '+')
	{
		if (c == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

t_stack	*make_stack(char *ptr, t_stack **b)
{
	char	**sp_str;
	t_stack	*a;
	t_stack	*new;	
	int		i;
	long	yoy;

	i = 0;
	a = NULL;
	new = NULL;
	sp_str = ft_split(ptr, 32);
	if (!sp_str)
		return (NULL);
	if (!check_valid_stack(sp_str))
		free_ever(ptr, sp_str, &a, b);
	while (sp_str[i])
	{
		yoy = ft_atoi(sp_str[i], sp_str, &a, b);
		if (yoy > INT_MAX || yoy < INT_MIN)
			free_ever(ptr, sp_str, &a, b);
		new = ft_lstnew(yoy);
		ft_lstadd_back(&a, new);
		i++;
	}
	freeee(sp_str);
	return (a);
}
