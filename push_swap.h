/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-laz <hben-laz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 02:58:26 by hben-laz          #+#    #+#             */
/*   Updated: 2024/04/02 10:17:05 by hben-laz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 5
// # endif



// typedef struct s_data
// {
// 	char	*buffer;
// }	t_data;


typedef struct s_list
{
	int				value;
	int				index;
	struct s_list	*next;
} t_list;

char	**ft_split(char const *s, char c);
long	ft_atoi(const char *str);

#endif