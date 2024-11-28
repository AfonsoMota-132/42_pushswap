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

# include "../libs/libft/libft.h"

typedef struct t_stack {
	int				content;
	int				id;
	struct t_stack	*next;
} t_stack;

typedef	struct s_data {
	t_stack	*stack_a;
	t_stack *stack_b;
	t_stack	*start_stack_a;
	t_stack *start_stack_b;
	int		size;
} t_data;

//		stack_checker		//

void	ft_putid(t_data **data);
int	ft_stacklen(t_stack *stack);
void	ft_stackchecker(int	ac, char **av);
int	ft_check_int(int ac, char **av);
int	ft_check_repeat(t_stack *stack);
int	ft_check_space(int ac, char **av);
//		Stack Maker			//

void	ft_stackadd_back(t_stack **stack, t_stack *new);
void	ft_stackadd_front(t_stack **stack, t_stack *new);
void	ft_stackrmv_front(t_stack **stack);
void	ft_stackrmv_back(t_stack **stack);
t_stack	*ft_stacklast(t_stack *stack);
t_stack *ft_stacknew(int content);
t_data	*ft_stack_maker(char **list_char);

//		Stack Moves			//

void	ft_stack_swap(t_stack **stack);
void	ft_push_stack(t_stack **dest, t_stack **source);
void	ft_rotate_stack(t_stack **stack);
void	ft_rrotate_stack(t_stack **stack);

//		Stack Sort			//

int	ft_check_sort(t_data *data);
void ft_radix(t_data **data);
#endif
