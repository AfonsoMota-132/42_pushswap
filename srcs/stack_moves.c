/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:33:14 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/26 09:37:45 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_stack_swap(t_stack **stack)
{
	t_stack	*stack_temp;
	int		temp;
	
	stack_temp = *stack;
	temp = stack_temp->content;
	stack_temp->content = stack_temp->next->content;
	stack_temp->next->content = temp;
}

void	ft_push_stack(t_stack **dest, t_stack **source)
{
	if (!*dest)
	{
		*dest = ft_stacknew((*source)->content);
	}
	else
	{
		ft_stackadd_front(dest, ft_stacknew((*source)->content));
	}
	(*dest)->next = NULL;
	ft_stackrmv_front(&(*source));
}

void	ft_rotate_stack(t_stack **stack)
{
	int	temp;

	temp = (*stack)->content;
	ft_stackrmv_front(&(*stack));
	ft_stackadd_back(&(*stack), ft_stacknew(temp));
}

void	ft_rrotate_stack(t_stack **stack)
{
	int	temp;
	temp = (*stack)->content;
	ft_stackrmv_back(&(*stack));
	ft_stackadd_front(&(*stack), ft_stacknew(temp));
}
