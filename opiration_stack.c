/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opiration_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:24:53 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/29 22:24:14 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, int flag)
{
	int	tmp;
	int	ord;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->content;
	ord = (*a)->ord;
	(*a)->content = (*a)->next->content;
	(*a)->ord = (*a)->next->ord;
	(*a)->next->content = tmp;
	(*a)->next->ord = ord;
	if (flag == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int flag)
{
	int	tmp;
	int	ord;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = (*b)->content;
	ord = (*b)->ord;
	(*b)->content = (*b)->next->content;
	(*b)->ord = (*b)->next->ord;
	(*b)->next->content = tmp;
	(*b)->next->ord = ord;
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
	t_stack	*ptr;

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
	t_stack	*ptr;

	if (!*b)
		return ;
	ptr = *b;
	*b = (*b)->next;
	ptr->next = *a;
	*a = ptr;
	if (flag == 1)
		write(1, "pa\n", 3);
}
