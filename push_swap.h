/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:26 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/18 22:23:13 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>



// typedef struct s_data
// {
// 	char	*buffer;
// }	t_data;


typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
} t_stack;

char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);
void	free_t_split(char **array);
void	ft_print_error();
t_stack *ft_lstnew(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_lstlast(t_stack *lst);
int		size_stack(t_stack *a);
t_stack	*ft_lstbefore_last(t_stack *lst);
void	check_nbr(char **buf, t_stack **stack);
int		is_sorted(t_stack *a);

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

#endif