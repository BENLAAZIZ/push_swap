/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_mix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:17:55 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/27 21:01:27 by hben-laz         ###   ########.fr       */
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

// int get_cost_mix(t_stack *x, int value, int size)
// {
// 	int pos = get_position(x, value); //2 
// 	int index = size - pos; // 9 - 2 = 7;

// 	if(index < size - pos)
// 		return index;
// 	else
// 		return (size - pos);
// }

int  get_cost_a_mix(int nbr, t_stack *a, t_donne *mix)
{
	t_stack	*ptr;
	int		value;
	// int		min;
	int		i;

	i = 0;
	ptr = a;
	value = ptr->content;
	// min = ptr->content;
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
	int	size;
	int	ca;
	int	cb;
	int val_b;

	mix->cost_b = -1;
	mix->cost_a = -1;
	ca = -1;
	cb = -1;
	size = size_stack(b);
    mix->total = 100000;
	t_stack *tmp = b;
	while (b)
	{
		val_b = b->content;
		cb = get_cost_mix(tmp, val_b, size);
		ca = get_cost_a_mix(val_b, a, mix);
		if (mix->total > ca + cb)
		{
			mix->value_b = val_b;
			mix->value_a = mix->value_a_modif;
			mix->cost_b = cb;
			mix->cost_a = ca;
			mix->total = mix->cost_a + mix->cost_b;
		}
		b = b->next;
	}
}

void	move_mix_a(t_stack **a, t_stack **b, t_donne *mix)
{
	int	i;
	int size_a;
	int size_b;
	int	pos_a;
	int	pos_b;

	i = 0;
	size_a = size_stack(*a);
	size_b = size_stack(*b);
	pos_a = get_position(*a, mix->value_a);
	pos_b = get_position(*b, mix->value_b);
	if (pos_a <= size_a / 2)
	{
		while (i < mix->cost_a)
		{
			ra(a, 1);
			i++;
		}
	}
	else
	{
		while (i < mix->cost_a)
		{
			rra(a, 1);
			i++;
		}
	}
	i = 0;
	if (pos_b <= size_b / 2)
	{
		while (i < mix->cost_b)
		{
			rb(b, 1);
			i++;
		}
	}
	else
	{
		while (i < mix->cost_b)
		{
			rrb(b, 1);
			i++;
		}
	}
	pa(a, b, 1);
}
