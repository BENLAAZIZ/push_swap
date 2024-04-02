/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:46 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/02 00:28:10 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void handel_number(char **buffer)
{
	int i = 0;
	int j;
	int nbr;
	while (buffer[i])
	{
		j = 0;
		while ((buffer[i][j] >= '0' && buffer[i][j] <= '9') && buffer[i][j])
			j++;
		if (!(buffer[i][j] >= '0' && buffer[i][j] <= '9') && buffer[i][j])
			break ;
		nbr = ft_atoi(buffer[i]);
		printf("nbr -> %d = %d\t\n-------------\n", i, nbr);
		i++;
	}
}
int check_data(char **v)
{
	int i = 1;
	char **buf;
	if (!v || !v[0])
		return(1);
	while (v[i])
	{
		buf = ft_split(v[i], ' ');
		if (!buf)
			return (1);
		else
			handel_number(buf);
		i++;
	}
	return 1;
}
int main(int c, char **v)
{
	
	if (c < 2)
		return (0);
	check_data(v);

	return 0;
}
