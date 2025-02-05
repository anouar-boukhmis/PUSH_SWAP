/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_5_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:35:04 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/05 14:48:54 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	is_there_anum(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			count++;
		else if (str[i] != '-' && str[i] != '+' && str[i] != 32)
			return (0);
		else if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
		i++;
	}
	return (count != 0);
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
