/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:23:47 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/28 14:50:25 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cas best rr **************************************************
int get_cost_rrr(t_stack *x, int value, int size)
{
	int i;
	
	i = 0;
	while (i < size)
	{
		if (i == 0 && x->content == value)
			return (0);
		if (x->content == value)
			break ;
		x = x->next;
		i++;
	}
	return (size - i);
}

int  get_cost_a_rrr(int nbr, t_stack *a, t_donne *rrr)
{
	t_stack	*ptr;
	int		value;
	int		min;
	int		i;

	i = 0;
	ptr = a;
	value = ptr->content;
	min = ptr->content;
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
		rrr->value_a_modif = get_min(a);
	else
		rrr->value_a_modif = value;
	return (get_cost_rrr(a, rrr->value_a_modif, size_stack(a)));
}

void best_rrr(t_stack *b, t_stack *a, t_donne *rrr)
{
	int	size;
	int	ca;
	int	cb;
	int	val_b;

	rrr->cost_b = -1;
	rrr->cost_a = -1;
	ca = -1;
	cb = -1;
	size = size_stack(b);
	t_stack *tmp = b;
    rrr->total = 100000;
	while (b)
	{
		val_b = b->content;
		cb = get_cost_rrr(tmp, val_b, size);
		ca = get_cost_a_rrr(val_b, a, rrr);
		if (rrr->total > ca && rrr->total > cb)
		{
			rrr->value_b = val_b;
			rrr->value_a = rrr->value_a_modif;
			rrr->cost_b = cb;
			rrr->cost_a = ca;
			if (cb > ca)
				rrr->total = cb;
			else
				rrr->total = ca;
		}
		b = b->next;
	}
}

void	move_rrr_a(t_stack **a, t_stack **b, t_donne *best_rrr)
{
	int	i;
	int size_a;
	int size_b;
	int	pos_a;
	int	pos_b;

	i = 0;
	size_a = size_stack(*a);
	size_b = size_stack(*b);
	pos_a = get_position(*a, best_rrr->value_a);
	pos_b = get_position(*b, best_rrr->value_b);
	if (best_rrr->cost_a > best_rrr->cost_b)
	{
		while (i < best_rrr->cost_b)
		{
			rrr(a, b, 1);
			i++;
		}
		while (i < best_rrr->cost_a)
		{
			rra(a, 1);
			i++;
		}
	}
	else 
	{
		while (i < best_rrr->cost_a)
		{
			rrr(a, b, 1);
			i++;
		}
		while (i < best_rrr->cost_b)
		{
			rrb(b, 1);
			i++;
		}
	}
	pa(a, b, 1);
}
// fin cas rrr rrr **************************************************