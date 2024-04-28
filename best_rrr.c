/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_rrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:23:47 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/28 22:35:29 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		rrr->value_a_modif = get_min(a);
	else
		rrr->value_a_modif = value;
	return (get_cost_rrr(a, rrr->value_a_modif, size_stack(a)));
}

void	best_rrr_init(t_stack *b, t_donne *best_rrr, t_var *var)
{
	
	best_rrr->cost_b = -1;
	best_rrr->cost_a = -1;
	var->ca = -1;
	var->cb = -1;
	var->size = size_stack(b);
    best_rrr->total = 100000;
}

void best_rrr(t_stack *b, t_stack *a, t_donne *rrr)
{
	t_stack *tmp;
	t_var	var;

	best_rrr_init(b, rrr, &var);
	tmp = b;
	while (b)
	{
		var.val_b = b->content;
		var.cb = get_cost_rrr(tmp, var.val_b, var.size);
		var.ca = get_cost_a_rrr(var.val_b, a, rrr);
		if (rrr->total > var.ca && rrr->total > var.cb)
		{
			rrr->value_b = var.val_b;
			rrr->value_a = rrr->value_a_modif;
			rrr->cost_b = var.cb;
			rrr->cost_a = var.ca;
			if (var.cb > var.ca)
				rrr->total = var.cb;
			else
				rrr->total = var.ca;
		}
		b = b->next;
	}
}

void	move_rrr_a(t_stack **a, t_stack **b, t_donne *best_rrr)
{
	int	i;

	i = -1;
	if (best_rrr->cost_a > best_rrr->cost_b)
	{
		while (++i < best_rrr->cost_b)
			rrr(a, b, 1);
		while (i++ < best_rrr->cost_a)
			rra(a, 1);
	}
	else 
	{
		while (++i < best_rrr->cost_a)
			rrr(a, b, 1);
		while (i++ < best_rrr->cost_b)
			rrb(b, 1);
	}
	pa(a, b, 1);
}
