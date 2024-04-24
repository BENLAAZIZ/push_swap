/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_mix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 19:17:55 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/24 19:20:09 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// cas best mixt **************************************************
int get_cost_mix(t_stack *x, int value, int size)
{
	int i = 0;
	//1_ get index of the value in the stack
	while (i < size)
	{
		if (x->content == value)
			break ;
		x = x->next;
		i++;
	}
	//2_ get the cost based on the index of the value (if the index is )
	if (i <= (size / 2))
	{
		return (i);
	}
	return (size - i);
}

int  get_cost_a(int nbr, t_stack *a)
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
		return (get_cost_mix(a, min, size_stack(a)));
	else
		return (get_cost_mix(a, value, size_stack(a)));
}

void best_mix(t_stack *b, t_stack *a, t_donne *best)
{
	int i;
	int	size;

	i = 0;
	best->cost_b = -1;
	best->cost_a = -1;
	size = size_stack(b);
    best->total = 100000;
	while (b)
	{
		best->cost_b = get_cost_mix(b, b->content, size);
		best->cost_a = get_cost_a_mix(b->content, a);
		if (best->total > best->cost_a + best->cost_b)
		{
			best->ord = i;
			best->total = best->cost_a + best->cost_b;
		}
		i++;
		b = b->next;
	}
}
// fin cas best mixt  **************************************************
// cas best rr **************************************************