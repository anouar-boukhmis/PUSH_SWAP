/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:02:01 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/04 22:26:18 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define  PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}t_stack;

char		*ft_strjoin(char *s1, char *s2);
long		ft_atoi(char *str, char **sp_str, t_stack **a, t_stack **b);
size_t		ft_strlen(char *str);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
char		**ft_split(char *s, char c);
t_stack		*make_stack(char *ptr, t_stack **b);
int			ft_lstsize(t_stack *lst);
void		give_index(t_stack **a);
void		give_pos(t_stack **stack);
int			check_sorted_stack(t_stack *a);
void		pb(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		sort_3(t_stack **a);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
void		sortfour(t_stack **a, t_stack **b);
void		sortfive(t_stack **a, t_stack **b);
void		sort_5_4(t_stack **a, t_stack **b);
void		sort_100_500(t_stack **a, t_stack **b);
int			is_comb(t_stack *a, int size);
void		ft_lstclear(t_stack **lst);
void		free_stack(t_stack **a, t_stack **b);
int			ft_isdigit(int c);
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
void		ft_lstdelone(t_stack *lst);
void		free_error(char **sp_str, t_stack **a, t_stack **b);
t_stack		*ft_lstnew(int cntnt);
char		*ft_strdup(char *s);
char		**ft_split(char*s, char c);
int			ft_strcmp(char *str1, char *str2);
int			check_valid_stack(char **str);
void		freeee(char **str);
int			count_words(char *s, char sep);
char		*arg_str(char **av);
t_stack		*swap_stack(t_stack *a);
t_stack		*pushx(t_stack **a, t_stack **b);
t_stack		*rotatx(t_stack *a);
t_stack		*rrx(t_stack *a);
int			signe_o(char c, int *i);

#endif