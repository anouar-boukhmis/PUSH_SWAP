/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:21:48 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/05 15:09:36 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	is_valable(char *str)
{
	if (ft_strcmp(str, "ra\n") == 0
		|| ft_strcmp(str, "rb\n") == 0
		|| ft_strcmp(str, "sa\n") == 0
		|| ft_strcmp(str, "sb\n") == 0
		|| ft_strcmp(str, "pa\n") == 0
		|| ft_strcmp(str, "pb\n") == 0
		|| ft_strcmp(str, "rra\n") == 0
		|| ft_strcmp(str, "rrb\n") == 0
		|| ft_strcmp(str, "rrr\n") == 0
		|| ft_strcmp(str, "ss\n") == 0
		|| ft_strcmp(str, "rr\n") == 0)
		return (1);
	return (0);
}

void	app_oper(char *oper, t_stack **a, t_stack **b)
{
	if (!oper)
		return ;
	if (ft_strcmp(oper, "ra\n") == 0)
		ra_bonus(a);
	if (ft_strcmp(oper, "rb\n") == 0)
		ra_bonus(b);
	if (ft_strcmp(oper, "rr\n") == 0)
		rr_bonus(a, b);
	if (ft_strcmp(oper, "sa\n") == 0)
		sa_bonus(a);
	if (ft_strcmp(oper, "sb\n") == 0)
		sa_bonus(b);
	if (ft_strcmp(oper, "ss\n") == 0)
		ss_bonus(a, b);
	if (ft_strcmp(oper, "pa\n") == 0)
		pa_bonus(a, b);
	if (ft_strcmp(oper, "pb\n") == 0)
		pa_bonus(b, a);
	if (ft_strcmp(oper, "rra\n") == 0)
		rra_bonus(a);
	if (ft_strcmp(oper, "rrb\n") == 0)
		rra_bonus(b);
	if (ft_strcmp(oper, "rrr\n") == 0)
		rrr_bonus(a, b);
}

void	read_ope(t_stack **a, t_stack **b)
{
	char	*operation;

	operation = get_next_line(0);
	while ((operation))
	{
		if (!is_valable(operation))
		{
			free(operation);
			errorexit(a, b);
		}
		app_oper(operation, a, b);
		free(operation);
		operation = get_next_line(0);
	}
	if (*b)
		write(1, "KO\n", 4);
	else if (check_sorted_stack(*a) == 1 && !*b)
		write(1, "OK\n", 4);
	else
		write(1, "KO\n", 4);
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
	give_index(&a);
	free(ptr);
	read_ope(&a, &b);
	free_stack(&a, &b);
}
