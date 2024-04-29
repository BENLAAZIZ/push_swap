/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 19:22:53 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/29 22:55:45 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	int		i;
	long	f;
	int		s;

	i = 0;
	f = 0;
	s = 1;
	if (*(str + i) == '+' || *(str + i) == '-')
	{
		if (*(str + i) == '-')
			s *= -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9' && f < 2147483649)
	{
		f = (f * 10) + (*(str + i)) - '0';
		i++;
	}
	return (f * s);
}

void	rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if (flag == 1)
		write(1, "rrr\n", 4);
}

int	get_position(t_stack *ptr, int value)
{
	int	i;

	i = 0;
	while (ptr)
	{
		if (ptr->content == value)
			break ;
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void	best_mix_init(t_stack *b, t_donne *mix, t_var *var)
{
	mix->cost_b = -1;
	mix->cost_a = -1;
	var->ca = -1;
	var->cb = -1;
	var->size = size_stack(b);
	mix->total = 100000;
}
