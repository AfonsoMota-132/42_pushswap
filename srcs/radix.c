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

void	ft_sort3(t_data **data)
{
	int	top;
	int	bot;
	int	mid;

	top = ft_stacklast((*data)->stack_a)->content;
	bot = (*data)->start_stack_a->content;
	mid = (*data)->start_stack_a->next->content;
	if (top < bot && bot < mid)
		ft_stack_rrotate_a(data);
	else if (top < mid && mid < bot)
	{
		ft_stack_swap_a(data);
		ft_stack_rrotate_a(data);
	}
	else if (bot < mid && top < mid)
	{
		ft_stack_swap_a(data);
		ft_stack_rotate_a(data);
	}
	else if (bot < top && top < mid)
		ft_stack_swap_a(data);
	else if (top > bot && bot > mid)
		ft_stack_swap_a(data);
	else if (mid < bot && mid < top)
		ft_stack_rotate_a(data);
}

void	ft_sort_4(t_data **data, int id)
{
	(*data)->stack_a = (*data)->start_stack_a;
	if ((*data)->stack_a->next->next->next->id == id)
		ft_stack_rrotate_a(data);
	else
		while ((*data)->stack_a->id != id)
			ft_stack_rotate_a(data);
	if (ft_check_sort(*data))
	{
		ft_stack_push_b(data);
		(*data)->stack_a = (*data)->start_stack_a;
		ft_sort3(data);
		(*data)->stack_a = (*data)->start_stack_a;
		ft_stack_push_a(data);
		(*data)->stack_a = (*data)->start_stack_a;
	}
}

void	ft_sort5(t_data **data)
{
	(*data)->stack_a = (*data)->start_stack_a;
	if ((*data)->stack_a->next->next->next->next->id == 0)
		ft_stack_rrotate_a(data);
	else
		while ((*data)->stack_a->id != 0)
			ft_stack_rotate_a(data);
	if (ft_check_sort(*data))
	{
		ft_stack_push_b(data);
		(*data)->stack_a = (*data)->start_stack_a;
		ft_sort_4(data, 1);
		(*data)->stack_a = (*data)->start_stack_a;
		ft_stack_push_a(data);
		(*data)->stack_a = (*data)->start_stack_a;
	}
}

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

	bits = -1;
	(*data)->stack_a = (*data)->start_stack_a;
	while (ft_check_sort(*data) && ++bits < 32)
	{
		i = -1;
		(*data)->stack_a = (*data)->start_stack_a;
		while (++i < (*data)->size)
		{
			if ((*data)->start_stack_a->id >> bits & 1)
				ft_stack_rotate_a(data);
			else
				ft_stack_push_b(data);
		}
		(*data)->stack_b = (*data)->start_stack_b;
		while ((*data)->stack_b)
		{
			ft_stack_push_a(data);
			(*data)->stack_b = (*data)->start_stack_b;
		}
		free((*data)->start_stack_b);
	}
	(*data)->stack_a = (*data)->start_stack_a;
}
