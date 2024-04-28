/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:35:10 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/28 18:23:42 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_cost_rr(t_stack *x, int value, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (x->content == value)
			break ;
		x = x->next;
		i++;
	}
	return (i);
}

int  get_cost_a_rr(int nbr, t_stack *a,  t_donne *best_rr)
{
	t_stack	*ptr;
	int		value;
	int		i;

	i = 0;
	ptr = a;
	value = ptr->content;
	while (ptr)
	{
		if (nbr < ptr->content )
		{
			if (nbr > value || value >= ptr->content)
			{
				value = ptr->content;
				i++;
			}
		}
		ptr = ptr->next;
	}
	if (i == 0)
		best_rr->value_a_modif = get_min(a);
	else
		best_rr->value_a_modif = value;
	return (get_cost_rr(a, best_rr->value_a_modif, size_stack(a)));
}

void best_rr(t_stack *b, t_stack *a, t_donne *best_rr)
{
	int	size;
	int	ca;
	int	cb;
	int val_b;
	t_stack *tmp;

	best_rr->cost_b = -1;
	best_rr->cost_a = -1;
	ca = -1;
	cb = -1;
	size = size_stack(b);
    best_rr->total = 100000;
	tmp = b;
	while (b)
	{
		val_b = b->content;
		cb = get_cost_rr(tmp, val_b, size);
		ca = get_cost_a_rr(val_b, a, best_rr);
		if (best_rr->total > ca && best_rr->total > cb)
		{
			best_rr->value_b = val_b;
			best_rr->value_a = best_rr->value_a_modif;
			best_rr->cost_b = cb;
			best_rr->cost_a = ca;
			if (cb > ca)
				best_rr->total = cb;
			else
				best_rr->total = ca;
		}
		b = b->next;
	}
}

void	move_rr_a(t_stack **a, t_stack **b, t_donne *best_rr)
{
	int	i;

	i = -1;
	if (best_rr->cost_a > best_rr->cost_b)
	{
		while (++i < best_rr->cost_b)
			rr(a, b, 1);
		while (i++ < best_rr->cost_a)
			ra(a, 1);
	}
	else 
	{
		while (++i < best_rr->cost_a)
			rr(a, b, 1);
		while (i++ < best_rr->cost_b)
			rb(b, 1);
	}
	pa(a, b, 1);
}
