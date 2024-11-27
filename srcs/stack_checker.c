/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:49:42 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/23 11:53:09 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	check_repeat(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		printf("a: %i\n", stack->content);
		temp = stack->next;
		while (temp)
		{
			if (temp->content == stack->content)
			{
				ft_printf("Equal!");
				exit (0);
			}
			if (!temp->next)
				break ;
			temp = temp->next;
		}
		if(!stack->next)
			break ;
		stack = stack->next;
	}
	return (0);
}
void	ft_stackchecker(int ac, char **av)
{
	if (ac == 2)
	{
		ft_check_int(ac, av);
	}
	else
	{
		ft_check_int(ac, av);
		ft_check_space(ac, av);
	}
}
int	ft_check_space(int	ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (av[i][j] == ' ')
			{
				ft_printf("Error\nIf you use multiple arguments. ");
				ft_printf("Please differ from using multiple numbers in 1\n");
				ft_printf("And don't use unecessary spaces!\n");
				exit (1);
			}
			j++;
		}
	}
	return (0);
}
int	ft_check_int(int ac, char **av)
{
	int	i;
	int	j;
	
	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ')
			{
				ft_printf("Error\nA char other than numbers was found!\n");
				exit (1);
			}
			j++;
		}
	}
	return (0);
}
