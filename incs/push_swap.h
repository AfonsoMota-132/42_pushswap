/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:37:34 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/23 11:38:21 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_stack {
	int				content;
	struct t_stack	*next;
} t_stack;

# include "../libs/libft/libft.h"

//		stack_checker		//

int	check_int(int ac, char **av);
int	check_repeat(t_stack *stack);

//		Stack Maker			//

void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackrmv_front(t_stack **stack);
void	ft_stackrmv_back(t_stack **stack);
t_stack	*ft_stacklast(t_stack *stack);
t_stack *ft_stacknew(int content);
t_stack	*stack_maker(char **list_char);

//		Stack Moves			//

void	ft_stack_swap(t_stack **stack);
void	ft_push_stack(t_stack **dest, t_stack **source);
void	ft_rotate_stack(t_stack **stack);
void	ft_rrotate_stack(t_stack **stack);

#endif
