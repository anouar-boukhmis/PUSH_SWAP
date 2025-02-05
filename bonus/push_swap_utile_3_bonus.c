/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:27:06 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/30 22:31:57 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*copy;

	if (!lst)
		return ;
	copy = *lst;
	while (copy)
	{
		temp = copy->next;
		ft_lstdelone(copy);
		copy = temp;
	}
	*lst = NULL;
}

void	free_error(char **sp_str, t_stack **a, t_stack **b)
{
	int	i;

	if (sp_str)
	{
		i = 0;
		while (sp_str[i])
		{
			free(sp_str[i]);
			i++;
		}
		free(sp_str);
	}
	if (a && *a)
		ft_lstclear(a);
	if (b && *b)
		ft_lstclear(b);
	write(2, "Error\n", 7);
	exit(1);
}

long	ft_atoi(char *str, char **sp_str, t_stack **a, t_stack **b)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		free_error(sp_str, a, b);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			free_error(sp_str, a, b);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

t_stack	*ft_lstnew(int cntnt)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new ->value = cntnt;
	new -> next = NULL;
	return (new);
}

char	*ft_strdup(char *s)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s);
	ptr = (char *)malloc(i + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
