/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:58:17 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/05 14:48:25 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*arg_str(char **av)
{
	int		i;
	char	*temp;

	i = 1;
	temp = NULL;
	while (av[i])
	{
		if (is_there_anum(av[i]) == 0)
		{
			if (temp)
				free(temp);
			write(1, "Error\n", 6);
			exit(0);
		}
		if (av[i][0] == '\0')
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		temp = ft_strjoin(temp, av[i]);
		temp = ft_strjoin(temp, " ");
		i++;
	}
	return (temp);
}

void	free_stack(t_stack **a, t_stack **b)
{
	ft_lstclear(a);
	ft_lstclear(b);
	exit(0);
}

int	main(int argc, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*ptr;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	ptr = arg_str(av);
	a = make_stack(ptr, &b);
	free(ptr);
	if (ft_lstsize(a) == 1)
		free_stack(&a, &b);
	give_index(&a);
	if (check_sorted_stack(a) == 1)
		free_stack(&a, &b);
	else if (ft_lstsize(a) == 2)
		sa(&a);
	else if (ft_lstsize(a) == 3)
		sort_3(&a);
	else if ((ft_lstsize(a) == 4 || ft_lstsize(a) == 5))
		sort_5_4(&a, &b);
	else
		sort_100_500(&a, &b);
	free_stack(&a, &b);
}
