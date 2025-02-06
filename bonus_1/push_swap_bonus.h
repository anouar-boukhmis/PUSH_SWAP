/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboukhmi <aboukhmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 21:06:50 by aboukhmi          #+#    #+#             */
/*   Updated: 2025/02/05 20:48:57 by aboukhmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# define BUFFER_SIZE 42

typedef struct s_list
{
	char	*str;
	void	*next;
}t_list;

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	struct s_stack	*next;
}t_stack;

void		sa_bonus(t_stack **a);
void		ss_bonus(t_stack **a, t_stack **b);
void		pa_bonus(t_stack **a, t_stack **b);
void		ra_bonus(t_stack **a);
void		rr_bonus(t_stack **a, t_stack **b);
void		rra_bonus(t_stack **a);
void		rrr_bonus(t_stack **a, t_stack **b);
void		free_stack(t_stack **a, t_stack **b);
void		errorexit(t_stack **a, t_stack **b);
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
int			is_comb(t_stack *a, int size);
void		ft_lstclear(t_stack **lst);
int			ft_isdigit(int c);
size_t		ft_strlcat(char *dst, char *src, size_t size);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
void		ft_lstdelone(t_stack *lst);
void		free_error(char **sp_str, t_stack **a, t_stack **b);
t_stack		*ft_lstnew(int cntnt);
char		*ft_strdup(char *s);
char		**ft_split(char*s, char c);
int			ft_strcmp(char *str1, char *str2);
int			is_instack(int number, t_stack *a);
void		freeee(char **str);
int			count_words(char *s, char sep);
char		*arg_str(char **av);
t_stack		*swap_stack(t_stack *a);
t_stack		*pushx(t_stack **a, t_stack **b);
t_stack		*rotatx(t_stack *a);
t_stack		*rrx(t_stack *a);
char		*get_next_line(int fd);
char		*ft_strchr_gnl(const char *s, int c);
char		*ft_strjoin_gnl(char const *s1, char const *s2);
char		*ft_strdup_gnl(const char *s1);
char		*ft_substr_gnl(char const *s, unsigned int start, size_t len);
size_t		ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen_gnl(const char *s);
int			is_there_anum(char *str);
t_list		*ft_lstnew_bns(char *str);
void		ft_lstclear_bns(t_list **lst);
void		ft_lstadd_back_bns(t_list **lst, t_list *new);
t_list		*ft_lstlast_bns(t_list *lst);
void		read_and_stock(t_stack **a, t_stack **b, t_list **lst_operation);
int			is_valable(char *str);

#endif