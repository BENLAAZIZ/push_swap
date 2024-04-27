/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:26 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/27 16:38:41 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_donne
{
	int	value_a_modif;
	int	value_a;
	int	value_b;
	int	cost_a;
	int	cost_b;
	int	total;
}	t_donne;


typedef struct s_stack
{
	int				content;
	int				ord;
	struct s_stack	*next;
} t_stack;

t_stack *ft_lstnew(int content);
t_stack	*ft_lstbefore_last(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	free_t_split(char **array);
void	ft_print_error();
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	check_nbr(char **buf, t_stack **stack);
int		size_stack(t_stack *a);
int		is_sorted(t_stack *a);
long	ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

void	sa(t_stack **a, int flag);
void	sb(t_stack **b, int flag);
void	ss(t_stack **a, t_stack **b, int flag);
void	pb(t_stack **a, t_stack **b, int flag);
void	pa(t_stack **a, t_stack **b, int flag);
void	ra(t_stack **a, int flag);
void	rb(t_stack **b, int flag);
void	rr(t_stack **a, t_stack **b, int flag);
void	rra(t_stack **a, int flag);
void	rrb(t_stack **b, int flag);
void	rrr(t_stack **a, t_stack **b, int flag);

int		get_position(t_stack *ptr, int value);

void	best_rr(t_stack *b, t_stack *a, t_donne *best_rr);
int		get_cost_rr(t_stack *x, int value, int size);
int 	get_cost_a_rr(int nbr, t_stack *a, t_donne *best_rr);
void	move_rr_a(t_stack **a, t_stack **b, t_donne *best_rr);

void	best_mix(t_stack *b, t_stack *a, t_donne *mix);
int		get_cost_mix(t_stack *x, int value, int size);
int 	get_cost_a_mix(int nbr, t_stack *a, t_donne *mix);
void	move_mix_a(t_stack **a, t_stack **b, t_donne *mix);

void	best_rrr(t_stack *b, t_stack *a, t_donne *best_rrr);
int		get_cost_rrr(t_stack *x, int value, int size);
int 	get_cost_a_rrr(int nbr, t_stack *a, t_donne *best_rrr);
void	move_rrr_a(t_stack **a, t_stack **b, t_donne *best_rrr);
int	get_min(t_stack *a);
void display_list(t_stack *a);
#endif