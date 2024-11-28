/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: passunca <passunca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:24:17 by passunca          #+#    #+#             */
/*   Updated: 2024/11/28 09:31:21 by passunca         ###   ########.fr       */
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

	bits = 0;
	i = -1;
	(*data)->stack_a = (*data)->start_stack_a;
	while (ft_check_sort(*data))
	{
		ft_printf("IDK\n");
		while (++i < (*data)->size)
		{
			ft_printf("IDK1\n");
			if ((*data)->stack_a->content >> bits & 1)
			{
				ft_printf("%i\n", (*data)->stack_a->content);
				ft_push_stack(&(*data)->stack_b, &(*data)->stack_a);
			}
			else
			{
				ft_printf("%i\n", (*data)->stack_a->content);
				ft_rotate_stack(&(*data)->stack_a);
			}
		}
		(*data)->stack_b = (*data)->start_stack_b;
		while ((*data)->stack_b)
			ft_push_stack(&(*data)->start_stack_a, &(*data)->stack_b);
		(*data)->stack_a = (*data)->start_stack_a;
		while (((*data)->stack_a))
		{
			ft_printf("%i\n", (*data)->stack_a->content);
			(*data)->stack_a = (*data)->stack_a->next;
		}
		i = -1;
		bits++;
	}
	if (!ft_check_sort(*data))
		ft_printf("Sorted!\n");
	else
		ft_printf("Not Sorted!\n");
	(*data)->stack_a = (*data)->start_stack_a;	
}
