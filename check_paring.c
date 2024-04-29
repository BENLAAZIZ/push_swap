/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_paring.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 01:24:39 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/29 22:38:00 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_arg(char **v, t_stack **stack)
{
	char	**buf;
	int		i;

	i = 1;
	if (!v)
		return (1);
	while (v[i])
	{
		buf = ft_split(v[i], ' ');
		if (!buf)
			return (1);
		check_nbr(buf, stack);
		free_t_split(buf);
		i++;
	}
	return (0);
}

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

int	is_duplicated(t_stack *head, int value)
{
	while (head)
	{
		if (head->content == value)
			return (1);
		head = head -> next;
	}
	return (0);
}

void	check_nbr(char **buf, t_stack **stack)
{
	int		i;
	long	nbr;
	t_stack	*new;

	i = 0;
	while (buf[i])
	{
		if (!ft_isdigit(buf[i]))
			free_split_and_stack(stack, buf);
		nbr = ft_atoi(buf[i]);
		if (nbr < -2147483648 || nbr > 2147483647)
			free_split_and_stack(stack, buf);
		if (is_duplicated(*stack, (int)nbr))
			free_split_and_stack(stack, buf);
		new = ft_lstnew((int)nbr);
		if (!new)
			free_split_and_stack(stack, buf);
		ft_lstadd_back(stack, new);
		i++;
	}
}

int	is_sorted(t_stack *a)
{
	if (!a || !a->next)
		return (1);
	while (a->next)
	{
		if (a->content > a->next->content)
			return (0);
		a = a -> next;
	}
	return (1);
}
