/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:35:20 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/09 01:58:55 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rb(t_stack **b, int flag)
{
	if(!*b || !(*b)->next)
		return ;
	t_stack *ptr;
	t_stack *last;

	ptr = *b;
	last = ft_lstlast(*b);
	last->next = ptr;
	(*b) = (*b)->next;
	ptr->next = NULL;
	if(flag == 1)
		write(1,"rb\n",3);
}

void rr(t_stack **a, t_stack **b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if(flag == 1)
		write(1,"rr\n",3);
}

void rra(t_stack **a, int flag)
{
	t_stack *last;
	t_stack *before_last;

	if(!*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a); // 7
	before_last = ft_lstbefore_last(*a); // 5
	before_last->next = NULL;
	last->next = *a;
	*a = last;
	if(flag == 1)
		write(1,"rra\n",4);
}

void rrb(t_stack **b, int flag)
{
	if(!*b || !(*b)->next)
		return ;
	t_stack *last;
	t_stack *before_last;
	last = ft_lstlast(*b); // 7
	before_last = ft_lstbefore_last(*b); // 5
	before_last->next = NULL;
	last->next = *b;
	*b = last;
	if(flag == 1)
		write(1,"rrb\n",4);
}

