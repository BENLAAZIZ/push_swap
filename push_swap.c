/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/28 16:19:17 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_list(t_stack *a)
{
	while(a)
	{
		printf("|  %d  |\n", a->content);
		a = a->next;
	}
	printf("\n");
}

int get_arg(char **v, t_stack **stack)
{
	char	**buf;
	int		i;

	i = 1;
	if (!v)
		return(0);
	while (v[i])
	{
		buf = ft_split(v[i], ' ');
		if (!buf)
			return (1);
		check_nbr(buf, stack);
		i++;
	}
	free_t_split(buf);
	return (0);
}

int	get_max(t_stack *a)
{
	int max;
	
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
	int min;
	
	min = a->content;
	while (a)
	{
		if (min > a->content)
			min = a->content;
		a = a -> next;
	}
	return (min);
}


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
	t_stack *max_node;
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

int	get_position(t_stack *ptr, int value)
{
	int i = 0;
	while (ptr)
	{
		if (ptr->content == value)
			break ;
		i++;
		ptr = ptr->next;
	}
	return (i);
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

int main(int ac, char **av)
{
	t_stack *a;
	t_stack *b;
	
	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	get_arg(av, &a);
	if(is_sorted(a))
		return (0);
	algorithme(&a, &b);
	int min = get_min(a);
	int pos = get_position(a, min);
	int size = size_stack(a);
	if(pos <= (size / 2))
	{
		while(min != a->content)
			ra(&a, 1);
	}
	else
	{
		while(min != a->content)
			rra(&a, 1);
	}
	// display_list(a);
	return 0;
}
