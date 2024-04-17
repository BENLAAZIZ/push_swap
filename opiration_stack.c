/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opiration_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:24:53 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/17 19:02:37 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
	if (flag == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if (flag == 1)
		write(1, "ss\n", 3);
}

void	pb(t_stack **a, t_stack **b, int flag)
{
	t_stack *ptr;
	
	if (!*a)
		return ;
	ptr = *a;
	*a = (*a)->next;
	ptr->next = *b;
	*b = ptr;
	if (flag == 1)
		write(1, "pb\n", 3);
}

void	pa(t_stack **a, t_stack **b, int flag)
{
	t_stack *ptr;
	
	if (!*b)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = *a;
	*a = ptr;
	if (flag == 1)
		write(1, "pa\n", 3);
}

void	ra(t_stack **a, int flag)
{
	t_stack	*last;
	t_stack	*ptr;
	
	if (!(*a) || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	ptr = *a;
	*a = (*a)->next;
	last->next = ptr;
	ptr->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int flag)
{
	t_stack	*ptr;

	if (!(*b) || !(*b)->next)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ft_lstlast(*b)->next = ptr;
	ptr->next = NULL;
	if (flag == 1)
		write(1, "rb\n", 3);	
}

void	rr(t_stack **a, t_stack **b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if (flag == 1)
		write(1, "rr\n", 3);
}

void	rra(t_stack **a, int flag)
{
	t_stack	*last;
	t_stack	*b_last;

	if (!(*a) || !(*a)->next)
		return ;
	last = ft_lstlast(*a);
	b_last = ft_lstbefore_last(*a);
	b_last->next = NULL;
	last->next = *a;
	*a = last;
	if (flag == 1)
		write(1, "rra\n", 4);
}


void	rrb(t_stack **b, int flag)
{
	t_stack	*last;
	t_stack	*b_last;

	if (!(*b) || !(*b)->next)
		return ;
	last = ft_lstlast(*b);
	b_last = ft_lstbefore_last(*b);
	b_last->next = NULL;
	last->next = *b;
	*b = last;
	if (flag == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}