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

int	check_signs(char **list_char)
{
	int	i;
	int	j;
	int	check;

	i = -1;
	while (list_char[++i] != NULL)
	{
		check = 0;
		j = -1;
		while (!ft_isdigit(list_char[i][++j]))
		{
			if ((list_char[i][j] == '-') && check == 0)
				check = 1;
			else if ((list_char[i][j] == '-') && check == 1)
			{
				ft_printf("Error\n");
				return (1);
			}
		}
	}
	return (0);
}

int	check_repeat(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (temp->content == stack->content)
			{
				ft_printf("Error\n");
				return (1);
			}
			if (!temp->next)
				break ;
			temp = temp->next;
		}
		if (!stack->next)
			break ;
		stack = stack->next;
	}
	return (0);
}

int	ft_stackchecker(int ac, char **av, t_data *data)
{
	char	**temp;
	int		i;

	i = 0;
	if (ac == 2)
	{
		if (ft_check_int(ac, av) || data->size < 2
			|| (av[1][1] == '\0' && av[1][0] == '-'))
			return (1);
		temp = ft_split(av[1], ' ');
		while (temp[i])
			i++;
		if (check_signs(temp))
		{
			ft_free_split(temp, i);
			return (1);
		}
		ft_checksize(temp);
		ft_free_split(temp, i);
		return (0);
	}
	if (ft_check_int(ac, av) || ft_check_space(ac, av))
		return (1);
	ft_checksize((av + 1));
	return (0);
}

int	ft_check_space(int ac, char **av)
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
				ft_printf("Error\n");
				return (1);
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
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && av[i][j] != '-')
			{
				ft_printf("Error\n");
				return (1);
			}
			j++;
		}
	}
	return (0);
}
