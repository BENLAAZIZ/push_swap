/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fuction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:03:31 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/29 22:54:10 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->content > (*a)->next->content)
		sa(a, 1);
}

void	sort_3(t_stack **a)
{
	int	max;

	max = get_max(*a);
	if (max == (*a)->content)
	{
		ra(a, 1);
		sort_2(a);
	}
	else if (max == (*a)->next->content)
	{
		rra(a, 1);
		sort_2(a);
	}
	else
		sort_2(a);
}

void	get_order(t_stack **a)
{
	t_stack	*max_node;
	t_stack	*ptr;
	int		order;
	int		max;

	order = size_stack(*a);
	while (order > 0)
	{
		max = -2147483648;
		ptr = *a;
		max_node = NULL;
		while (ptr)
		{
			if (ptr->ord == 0 && ptr->content > max)
			{
				max = ptr->content;
				max_node = ptr;
			}
			ptr = ptr->next;
		}
		max_node->ord = order;
		order--;
	}
}

int	get_max(t_stack *a)
{
	int	max;

	max = a->content;
	while (a)
	{
		if (max < a->content)
			max = a->content;
		a = a->next;
	}
	return (max);
}

int	get_min(t_stack *a)
{
	int	min;

	min = a->content;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a -> next;
	}
	return (min);
}
