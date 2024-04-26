/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:35:10 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/26 19:01:57 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cas best rr **************************************************
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
			if (nbr > value || value > ptr->content)
			{
				value = ptr->content;
				i++;
			}
		}
		if (min > ptr->content)
			min = ptr->content;
		ptr = ptr->next;
	}
	if (i == 0)
	{
		best_rr->value_a_modif = min;
		return (get_cost_mix(a, min, size_stack(a)));
	}
	else
	{
		best_rr->value_a_modif = value;
		return (get_cost_mix(a, value, size_stack(a)));
	}
}

void best_rr(t_stack *b, t_stack *a, t_donne *best_rr)
{
	int	size;
	int	ca;
	int	cb;

	best_rr->cost_b = -1;
	best_rr->cost_a = -1;
	ca = -1;
	cb = -1;
	size = size_stack(b);
    best_rr->total = 100000;
	while (b)
	{
		cb = get_cost_rr(b, b->content, size);
		ca = get_cost_a_rr(b->content, a, best_rr);
		if (best_rr->total > ca && best_rr->total > cb)
		{
			best_rr->value_b = b->content;
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
	int size_a;
	int size_b;
	int	pos_a;
	int	pos_b;

	i = 0;
	size_a = size_stack(*a);
	size_b = size_stack(*b);
	pos_a = get_position(*a, best_rr->value_a);
	pos_b = get_position(*b, best_rr->value_b);
	if (best_rr->cost_a > best_rr->cost_b)
	{
		while (i < best_rr->cost_b)
		{
			rr(a, b, 1);
			i++;
		}
		while (i < best_rr->cost_a)
		{
			ra(a, 1);
			i++;
		}
	}
	else 
	{
		while (i < best_rr->cost_a)
		{
			rr(a, b, 1);
			i++;
		}
		while (i < best_rr->cost_b)
		{
			rb(b, 1);
			i++;
		}
	}
	pa(a, b, 1);
}
// fin cas best rr **************************************************