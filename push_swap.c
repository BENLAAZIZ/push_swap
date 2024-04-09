/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/09 01:31:56 by hben-laz         ###   ########.fr       */
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


int get_arg(char **v, t_stack **list)
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
		check_nbr(buf, list);
		i++;
	}
	free_t_split(buf);
	return (0);
}

int main(int c, char **v)
{
	t_stack *a;
	t_stack *b;
	
	a = NULL;
	b = NULL;
	if (c < 2)
		return (0);
	get_arg(v, &a);
	if(is_sorted(a))
		return (0);
	// algorithme(&a);
	display_list(a);
	return 0;
}
