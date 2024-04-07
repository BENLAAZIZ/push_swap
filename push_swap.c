/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/07 06:29:17 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-' || s[0] == '+')
		i++;
	if (!(s[i] >= '0' && s[i] <= '9'))
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
int is_duplicated(t_stack *head, int value)
{
	while(head)
	{
		if(head->content == value)
			return (1);
		head = head -> next;
	}
	return (0);
}
void display_list(t_stack *a)
{
	while(a)
	{
		printf("%d ", a->content);
		a = a->next;
	}
	printf("\n");
}
void	check_nbr(char **buf, t_stack **list)
{
	int	i;
	long	nbr;
	t_stack *new;
	
	i = 0;
	while (buf[i])
	{
		if (!ft_isdigit(buf[i]))
			ft_print_error();
		nbr = ft_atoi(buf[i]);
		if (nbr <  -2147483648  || nbr > 2147483647)
			ft_print_error();
		if(is_duplicated(*list, (int)nbr))
		{
			ft_print_error();
			return ;
		}
		new = ft_lstnew((int)nbr);
		if (!new)
		 	ft_print_error();
		ft_lstadd_back(list, new);
		i++;
	}
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
void sa(t_stack **a, int flag)
{
	int tmp;
	
	if(!*a || !(*a)->next)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	if(flag == 1)
		write(1,"sa\n",3);
}
void sb(t_stack **b, int flag)
{
	int tmp;
	if(!*b || !(*b)->next)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;	
	if(flag == 1)
		write(1,"sa\n",3);
}
void ss(t_stack **a, t_stack **b, int flag)
{
	sa(a, 0);
	sb(b, 0);
	if(flag == 1)
		write(1,"ss\n",3);
}

void pa(t_stack **a, t_stack **b, int flag)
{
	if (!*b)
		return ;
	t_stack *ptr;
	ptr = *b;
	(*b) = (*b)->next;
	ptr->next = *a;
	*a = ptr;
	if(flag == 1)
		write(1,"pa\n",3);
}
void pb(t_stack **a, t_stack **b, int flag)
{
	if (!*a)
		return ;
	t_stack *ptr;
	
	ptr = *a;
	(*a) = (*a)->next;
	ptr->next = *b;
	(*b) = ptr;
	if(flag == 1)
		write(1,"pb\n",3);
}
 
void ra(t_stack **a, int flag)
{
	if(!*a || !(*a)->next)
		return ;
	t_stack *ptr;
	t_stack *last;

	ptr = *a;
	last = ft_lstlast(*a);
	last->next = ptr;
	(*a) = (*a)->next;
	ptr->next = NULL;
	if(flag == 1)
		write(1,"ra\n",3);
}

void rb(t_stack **b, int flag)
{
	if(!*b || !(*b)->next)
		return ;
	t_stack *ptr;
	t_stack *last;

	ptr = *b;
	last = ft_lstlast(*b);
	last->next = ptr;
	(*b) = (*b)->next;
	ptr->next = NULL;
	if(flag == 1)
		write(1,"rb\n",3);
}

void rr(t_stack **a, t_stack **b, int flag)
{
	ra(a, 0);
	rb(b, 0);
	if(flag == 1)
		write(1,"rr\n",3);
}

void rra(t_stack **a, int flag)
{
	t_stack *last;
	t_stack *before_last;

	if(!*a || !(*a)->next)
		return ;
	last = ft_lstlast(*a); // 7
	before_last = ft_lstbefore_last(*a); // 5
	before_last->next = NULL;
	last->next = *a;
	*a = last;
	if(flag == 1)
		write(1,"rra\n",4);
}

void rrb(t_stack **b, int flag)
{
	if(!*b || !(*b)->next)
		return ;
	t_stack *last;
	t_stack *before_last;
	last = ft_lstlast(*b); // 7
	before_last = ft_lstbefore_last(*b); // 5
	before_last->next = NULL;
	last->next = *b;
	*b = last;
	if(flag == 1)
		write(1,"rrb\n",4);
}

void rrr(t_stack **a, t_stack **b, int flag)
{
	rra(a, 0);
	rrb(b, 0);
	if(flag == 1)
		write(1,"rrr\n",4);
}
int is_sorted(t_stack *a)
{
	if(!a || !a->next)
		return (1);
	while(a->next)
	{
		if(a->content > a->next->content)
			return (0);
		a = a -> next;
	}
	return (1);
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
