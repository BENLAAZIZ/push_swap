/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:35:10 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/29 22:33:56 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cost_rr(t_stack *x, int value, int size)
{
	int	i;

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

int	get_cost_a_rr(int nbr, t_stack *a, t_donne *best_rr)
{
	t_stack	*ptr;
	int		value;
	int		i;

	i = 0;
	ptr = a;
	value = ptr->content;
	while (ptr)
	{
		if (nbr < ptr->content)
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

void	best_rr_init(t_stack *b, t_donne *best_rr, t_var *var)
{
	best_rr->cost_b = -1;
	best_rr->cost_a = -1;
	var->ca = -1;
	var->cb = -1;
	var->size = size_stack(b);
	best_rr->total = 100000;
}

void	best_rr(t_stack *b, t_stack *a, t_donne *best_rr)
{
	t_stack	*tmp;
	t_var	var;

	best_rr_init(b, best_rr, &var);
	tmp = b;
	while (b)
	{
		var.val_b = b->content;
		var.cb = get_cost_rr(tmp, var.val_b, var.size);
		var.ca = get_cost_a_rr(var.val_b, a, best_rr);
		if (best_rr->total > var.ca && best_rr->total > var.cb)
		{
			best_rr->value_b = var.val_b;
			best_rr->value_a = best_rr->value_a_modif;
			best_rr->cost_b = var.cb;
			best_rr->cost_a = var.ca;
			if (var.cb > var.ca)
				best_rr->total = var.cb;
			else
				best_rr->total = var.ca;
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
