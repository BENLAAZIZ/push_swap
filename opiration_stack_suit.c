/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opiration_stack_suit.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:36:14 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/28 19:30:10 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"


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
