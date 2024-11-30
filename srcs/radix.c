/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 08:48:06 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/29 08:51:17 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_putid(t_data **data)
{
	int	max;
	int	index;

	index = 0;
	max = 2147483647;
	while (index < (*data)->size)
	{
		max = 2147483647;
		(*data)->stack_a = (*data)->start_stack_a;
		while ((*data)->stack_a)
		{
			if ((*data)->stack_a->content < max && (*data)->stack_a->id == -1)
				max = (*data)->stack_a->content;
			(*data)->stack_a = (*data)->stack_a->next;
		}
		(*data)->stack_a = (*data)->start_stack_a;
		while ((*data)->stack_a)
		{
			if ((*data)->stack_a->content == max)
				(*data)->stack_a->id = index;
			(*data)->stack_a = (*data)->stack_a->next;
		}
		index++;
	}
}

void	ft_radix(t_data **data)
{
	int	bits;
	int	i;
	/*int	bits_max;*/

	bits = -1;
	i = -1;
	(*data)->stack_a = (*data)->start_stack_a;
	while (ft_check_sort(*data) && ++bits < (*data)->size)
	{
		(*data)->stack_a = (*data)->start_stack_a;
		while (++i < (*data)->size)
		{
			if ((*data)->stack_a->id >> bits & 1)
				ft_stack_rotate_a(data);
			else
				ft_stack_push_a(data);
		}
		(*data)->stack_b = (*data)->start_stack_b;
		while ((*data)->stack_b)
			ft_stack_push_b(data);
		free((*data)->start_stack_b);
		(*data)->stack_a = (*data)->start_stack_a;
		i = -1;
	}
	(*data)->stack_a = (*data)->start_stack_a;
}
