/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/02 10:29:46 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




void	free_t_split(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}


void	ft_print_error()
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_isdigit(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}
void	check_nbr(char **buf)
{
	int	i;
	long	nbr;
	
	i = 0;
	while (buf[i])
	{
		if (!ft_isdigit(buf[i]))
			ft_print_error();
		nbr = ft_atoi(buf[i]);
		if (nbr <  -2147483648  || nbr > 2147483647)
			ft_print_error();
		printf("buf[%d] = %ld \n---------\n", i, nbr);
		i++;
	}
}

int get_arg(char **v)
{
	char	**buf;
	int		i;

	i = 1;
	if (!v || !v[0])
		return(0);
	while (v[i])
	{
		buf = ft_split(v[i], ' ');
		if (!buf)
			return (1);
		check_nbr(buf);
		free_t_split(buf);
		i++;
	}
	return 1;
}

int main(int c, char **v)
{
	if (c < 2)
		return (0);
	get_arg(v);

	return 0;
}
