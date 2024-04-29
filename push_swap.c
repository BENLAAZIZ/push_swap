/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/29 21:13:15 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_list(t_stack *a)
{
	while(a)
	{
		printf("|  %d  (%d)|\n", a->content, a->ord);
		a = a->next;
	}
	printf("\n");
}

void	move_action(t_stack **a, t_stack **b)
{
	t_donne	mix;
	t_donne	rr;
	t_donne	rrr;

	while (b && *b)
	{
		best_mix(*b, *a, &mix);
		best_rr(*b, *a, &rr);
		best_rrr(*b, *a, &rrr);
		if (rr.total <= mix.total && rr.total <= rrr.total)
			move_rr_a(a, b, &rr);
		else if (rrr.total <= mix.total && rrr.total <= rr.total)
			move_rrr_a(a, b, &rrr);
		else
			move_mix_a(a, b, &mix);
	}
}

void	sort_all(t_stack **a, t_stack **b)
{
	t_stack *ptr;
	int		mid;
	int		size;
	
	ptr = *a;
	size = size_stack(*a);
	mid = size / 2;
	get_order(a);
	while (size > 3)
	{
		if ((*a)->ord <= mid)
			pb(a, b, 1);
		else
		{
			pb(a, b, 1);
			rb(b, 1);
		}
		size--;
	}
	sort_3(a);
	move_action(a, b);
}

void	algorithme(t_stack **a, t_stack **b)
{
	int	size;

	if (!(*a) || !(*a)->next)
		return ;
	size = size_stack(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else 
		sort_all(a, b);
}

void	final_operation(t_stack **a)
{
	int	min;
	int pos;
	int size;

	min = get_min(*a);
	pos = get_position(*a, min);
	size = size_stack(*a);
	if(pos <= (size / 2))
	{
		while(min != (*a)->content)
			ra(a, 1);
	}
	else
	{
		while(min != (*a)->content)
			rra(a, 1);
	}
}

void	v()
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;

	// atexit(v);
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (get_arg(av, &a))
		return (ft_print_error(&a), 0);
	if(is_sorted(a))
		return (ft_clear_stack(&a), 0);
	algorithme(&a, &b);
	final_operation(&a);
	// display_list(a);
	ft_clear_stack(&a);
	return 0;
}
// ./push_swap "  1 2 -2 +9   "     -9
