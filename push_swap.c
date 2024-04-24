/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/24 19:26:38 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void display_list(t_stack *a)
{
	while(a)
	{
		printf(" ( content : %d order : (%d))\n", a->content, a->ord);
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


// cas best mixt **************************************************
// int get_cost_mix(t_stack *x, int value, int size)
// {
// 	int i = 0;
// 	//1_ get index of the value in the stack
// 	while (i < size)
// 	{
// 		if (x->content == value)
// 			break ;
// 		x = x->next;
// 		i++;
// 	}
// 	//2_ get the cost based on the index of the value (if the index is )
// 	if (i <= (size / 2))
// 	{
// 		return (i);
// 	}
// 	return (size - i);
// }

// int  get_cost_a(int nbr, t_stack *a)
// {
// 	t_stack	*ptr;
// 	int		value;
// 	int		min;
// 	int		i;

// 	i = 0;
// 	ptr = a;
// 	value = ptr->content;
// 	min = ptr->content;
// 	while (ptr)
// 	{
// 		if (nbr < ptr->content )
// 		{
// 			if (nbr > value || value > ptr->content)
// 			{
// 				value = ptr->content;
// 				i++;
// 			}
// 		}
// 		if (min > ptr->content)
// 			min = ptr->content;
// 		ptr = ptr->next;
// 	}
// 	if (i == 0)
// 		return (get_cost_mix(a, min, size_stack(a)));
// 	else
// 		return (get_cost_mix(a, value, size_stack(a)));
// }

// void best_mix(t_stack *b, t_stack *a, t_donne *best)
// {
// 	int i;
// 	int	size;

// 	i = 0;
// 	best->cost_b = -1;
// 	best->cost_a = -1;
// 	size = size_stack(b);
//     best->total = 100000;
// 	while (b)
// 	{
// 		best->cost_b = get_cost_mix(b, b->content, size);
// 		best->cost_a = get_cost_a_mix(b->content, a);
// 		if (best->total > best->cost_a + best->cost_b)
// 		{
// 			best->ord = i;
// 			best->total = best->cost_a + best->cost_b;
// 		}
// 		i++;
// 		b = b->next;
// 	}
// }
// fin cas best mixt  **************************************************
// cas best rr **************************************************
int get_cost_rr(t_stack *x, int value, int size)
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
	return (i);
}
int  get_cost_a_rr(int nbr, t_stack *a)
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
		return (get_cost_rr(a, min, size_stack(a)));
	else
		return (get_cost_rr(a, value, size_stack(a)));
}
void best_rr(t_stack *b, t_stack *a, t_donne *rr)
{
	int i;
	int	size;

	i = 0;
	rr->cost_b = -1;
	rr->cost_a = -1;
	size = size_stack(b);
    rr->total = 100000;
	// while (b)
	// {
	// 	rr->cost_b = get_cost_rr(b, b->content, size);
	// 	rr->cost_a = get_cost_a_mix(b->content, a);
	// 	if (rr->total > rr->cost_a + rr->cost_b)
	// 	{
	// 		rr->ord = i;
	// 		rr->total = rr->cost_a + rr->cost_b;
	// 	}
	// 	i++;
	// 	b = b->next;
	// }
	rr->cost_b = get_cost_rr(b, b->content, size);
	rr->cost_a = get_cost_a_rr(b->content, a);
	printf("\n cost_b rr %d\n", rr->cost_b);
	printf("\n cost_a rr %d\n", rr->cost_a);

}
// fin cas best rr **************************************************

void	move_action(t_stack **a, t_stack **b)
{
	// t_donne	*mix;
	t_donne	rr;
	// t_donne	*rrr;
	t_stack *ptr;
	ptr = *a;
		best_rr(*b, *a, &rr);
	// while (b)
	// {
	// 	best_mix(*b, *a, mix);
	// 	// move_to_a()
	// }
	
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
		if ((*a)->ord < mid)
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
		// display_list(*a);
		// display_list(*b);
}

void	algorithme(t_stack **a, t_stack **b)
{
	int	size;

	if (!(*a) || !(*a)->next)
		return ;
	size = size_stack(*a);
	// printf("\n------ size : %d -----\n", size);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else 
	{
	sort_all(a, b);
		// display_list(*a);
		// display_list(*b);
	}
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
	display_list(a);
	display_list(b);
	return 0;
}
