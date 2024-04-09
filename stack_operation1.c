/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:34:31 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/09 01:36:07 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void sa(t_stack **a, int flag)
{
	int tmp;
	
	if(!*a || !(*a)->next)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if(flag == 1)
		write(1,"sa\n",3);
}

void sb(t_stack **b, int flag)
{
	int tmp;
	if(!*b || !(*b)->next)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;	
	if(flag == 1)
		write(1,"sa\n",3);
}

void ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if(flag == 1)
		write(1,"ss\n",3);
}

void pa(t_stack **a, t_stack **b, int flag)
{
	if (!*b)
		return ;
	t_stack *ptr;
	ptr = *b;
	(*b) = (*b)->next;
	ptr->next = *a;
	*a = ptr;
	if(flag == 1)
		write(1,"pa\n",3);
}

void pb(t_stack **a, t_stack **b, int flag)
{
	if (!*a)
		return ;
	t_stack *ptr;
	
	ptr = *a;
	(*a) = (*a)->next;
	ptr->next = *b;
	(*b) = ptr;
	if(flag == 1)
		write(1,"pb\n",3);
}
 
void ra(t_stack **a, int flag)
{
	if(!*a || !(*a)->next)
		return ;
	t_stack *ptr;
	t_stack *last;

	ptr = *a;
	last = ft_lstlast(*a);
	last->next = ptr;
	(*a) = (*a)->next;
	ptr->next = NULL;
	if(flag == 1)
		write(1,"ra\n",3);
}

