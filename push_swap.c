/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/18 22:46:44 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void display_list(t_stack *a)
{
	while(a)
	{
		printf("%d ", a->content);
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
void sort_two(t_stack **a)
{
	if((*a)->content > (*a)->next->content)
		sa(a, 1);
}

int get_max(t_stack *a)
{
	int max;
	
	if(!a)
		return (0);
	max = a->content;
	while(a)
	{
		if(max < a->content)
			max = a->content;
		a = a->next;
	}
	return (max);
}
void sort_three(t_stack **a)
{   
	int max;
	
	max = get_max(*a);
	if(max == (*a)->content)
	{
		ra(a, 1);
		sort_two(a);
	}
	else if (max == (*a)->next->content)
	{
		rra(a, 1);
		sort_two(a);
	}
	else
		sort_two(a);
}
void algorithme(t_stack **a, t_stack **b)
{
	int size;

	if(!*a)
		return ;
	
	size = size_stack(*a);
	if(size == 2)
		sort_two(a);
	else if(size == 3)
		sort_three(a);
	else
	{
		while (size > 3)
		{
			pb(a, b, 1);
			size--;
		}
		sort_three(a);
		// best_move_algo(a, b);
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
	// display_list(a);
	// display_list(b);
	return 0;
}
