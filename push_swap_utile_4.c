/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utile_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:32:08 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/05 14:20:28 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	word_len(char *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != sep && s[i] != 9)
		i++;
	return (i);
}

char	**free_mem(char **c, int i)
{
	int	index;

	index = 0;
	while (index < i)
	{
		free(c[index]);
		index++;
	}
	free(c);
	return (NULL);
}

char	**ft_split(char*s, char c)
{
	char	**arr;
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	arr = (char **)malloc(sizeof(char *) * (count_words(str, c) + 1));
	if (!arr)
		return (NULL);
	while (i < count_words((char *)s, c))
	{
		while (*str == c)
			str++;
		arr[i] = (char *)malloc(sizeof(char) *(word_len(str, c) + 1));
		if (!arr[i])
			return (free_mem(arr, i));
		ft_strlcpy(arr[i], str, (word_len(str, c) + 1));
		str = str + word_len(str, c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int	ft_strcmp(char *str1, char *str2)
{
	unsigned char	*ptr;
	unsigned char	*ptr1;
	size_t			i;

	ptr = (unsigned char *)str1;
	ptr1 = (unsigned char *)str2;
	i = 0;
	while ((str1[i] != '\0' || str2[i] != '\0') && str1[i] == str2[i])
		i++;
	return (ptr[i] - ptr1[i]);
}

int	check_valid_stack(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 1;
		while (str[i + j])
		{
			if (ft_strcmp(str[i], str[i + j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
