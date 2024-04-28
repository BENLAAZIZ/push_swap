/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_mix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:17:55 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/28 21:34:14 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_cost_mix(t_stack *x, int value, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (x->content == value)
			break ;
		i++;
		x = x->next;
	}
	if (i <= (size / 2))
		return (i);
	return (size - i);
}

int  get_cost_a_mix(int nbr, t_stack *a, t_donne *mix)
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
		mix->value_a_modif = get_min(a);
	else
		mix->value_a_modif = value;		
	return (get_cost_mix(a, mix->value_a_modif, size_stack(a)));
}

void best_mix(t_stack *b, t_stack *a, t_donne *mix)
{
	t_stack *tmp;
	t_var	var;

	best_mix_init(b, mix, &var);
	tmp = b;
	while (b)
	{
		var.val_b = b->content;
		var.cb = get_cost_mix(tmp, var.val_b, var.size);
		var.ca = get_cost_a_mix(var.val_b, a, mix);
		if (mix->total > var.ca + var.cb)
		{
			mix->value_b = var.val_b;
			mix->value_a = mix->value_a_modif;
			mix->cost_b = var.cb;
			mix->cost_a = var.ca;
			mix->total = mix->cost_a + mix->cost_b;
		}
		b = b->next;
	}
}

void	move_mix_b_to_a(t_stack **a, t_stack **b, t_donne *mix, int i)
{
	if (mix->pos_a <= (size_stack(*a) / 2))
	{
		while (i++ < mix->cost_a)
			ra(a, 1);
	}
	else
	{
		while (i++ < mix->cost_a)
			rra(a, 1);
	}
	i = 0;
	if (mix->pos_b <= (size_stack(*b) / 2))
	{
		while (i++ < mix->cost_b)
			rb(b, 1);
	}
	else
	{
		while (i++ < mix->cost_b)
			rrb(b, 1);
	}
	pa(a, b, 1);
}

void	move_mix_a(t_stack **a, t_stack **b, t_donne *mix)
{
	mix->pos_a = get_position(*a, mix->value_a);
	mix->pos_b = get_position(*b, mix->value_b);
	move_mix_b_to_a(a, b, mix, 0);
}
