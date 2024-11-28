/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:29:05 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/28 20:32:15 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_stack_swap_a(t_data **data)
{
	int	temp;

	(*data)->stack_a = (*data)->start_stack_a;
	temp = (*data)->stack_a->content;
	(*data)->stack_a->content = (*data)->stack_a->next->content;
	(*data)->stack_a->next->content = temp;
}

void	ft_stack_push_a(t_data **data)
{
	(*data)->stack_a = (*data)->start_stack_a;
	if (!(*data)->start_stack_b)
	{
		(*data)->start_stack_b = ft_stacknew((*data)->stack_a->content);
		(*data)->start_stack_b->next = NULL;
	}
	else
		ft_stackadd_front(&(*data)->start_stack_b, ft_stacknew((*data)->stack_a->content));
	(*data)->stack_b = (*data)->start_stack_b;
	(*data)->stack_b->id = -1;
	(*data)->stack_a = (*data)->start_stack_a->next;
	ft_stackrmv_front(&(*data)->start_stack_a);
	(*data)->start_stack_a = (*data)->stack_a;
}

void	ft_stack_rotate_a(t_data **data)
{
	int	temp;
	int	check;

	if ((*data)->stack_a->id == -1)
		check = -1;
	else
		check = 0;
	(*data)->stack_a = (*data)->start_stack_a;
	temp = (*data)->stack_a->content;
	ft_stackrmv_front(&(*data)->stack_a);
	ft_stackadd_back(&(*data)->stack_a, ft_stacknew(temp));
	(*data)->start_stack_a = (*data)->stack_a;
	if (check == -1)
	{
		(*data)->stack_a->id = -1;
		ft_stacklast((*data)->stack_a)->id = -1;
	}
}

void	ft_stack_rrotate_a(t_data **data)
	{
	int	temp;
	int	check;

	if ((*data)->stack_a->id == -1)
		check = -1;
	else
		check = 0;
	(*data)->stack_a = (*data)->start_stack_a;
	temp = ft_stacklast((*data)->stack_a)->content;
	ft_stackrmv_back(&(*data)->stack_a);
	ft_stackadd_front(&(*data)->stack_a, ft_stacknew(temp));
	(*data)->start_stack_a = (*data)->stack_a;
	if (check == -1)
		(*data)->stack_a->id = -1;
}
