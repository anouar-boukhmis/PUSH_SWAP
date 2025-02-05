/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:32:13 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/01/30 22:31:53 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	p;
	size_t	j;

	if (!dst && size == 0)
		return (ft_strlen(src));
	i = ft_strlen(dst);
	p = i;
	if (i >= size)
		return (ft_strlen(src) + size);
	else
	{
		j = 0;
		while (i < size - 1 && src[j])
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		return (ft_strlen(src) + p);
	}
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	if (src && size != 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
	return (0);
}

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	free(lst);
}
