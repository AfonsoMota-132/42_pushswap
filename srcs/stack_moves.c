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
void	ft_stackadd_front(t_stack **stack, t_stack *new)
{
	new->next= *stack;
	*stack = new;
}

void	ft_push_stack(t_stack **dest, t_stack **source)
{
	t_stack	*src_temp;
	t_stack	*dest_temp;
	/*t_stack *temp;*/

	src_temp = *source;
	dest_temp = *dest;
	if (!*dest)
	{
		dest_temp = ft_stacknew(src_temp->content);
		dest_temp->next = NULL;
	}
	else
	{
		ft_stackadd_front(dest, ft_stacknew(src_temp->content));
	}
}
