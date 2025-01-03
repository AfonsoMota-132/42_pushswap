/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 11:39:05 by afogonca          #+#    #+#             */
/*   Updated: 2024/11/23 11:40:56 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	*ft_checksize(char **av)
{
	int	i;

	i = 0;
	while (av[i] != NULL)
	{
		if (ft_strlen(av[i]) > 11)
		{
			ft_printf("Error\n");
			return (NULL);
		}
		i++;
	}
	return (0);
}

int	ft_sort(t_data **data)
{
	if (!ft_check_sort(*data) || (*data)->size == 1)
		return (1);
	else if ((*data)->size == 2)
		ft_stack_swap_a(data);
	else if ((*data)->size == 3)
		ft_sort3(data);
	else if ((*data)->size == 4)
		ft_sort_4(data, 0);
	else if ((*data)->size == 5)
		ft_sort5(data);
	else
		ft_radix(data);
	return (0);
}

int	ft_checkint(char **list_char)
{
	long	content;
	int		i;

	i = 0;
	while (list_char[i] != NULL)
	{
		content = ft_atol(list_char[i]);
		if (content > 2147483647 || content < -2147483648)
		{
			ft_printf("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_sort(t_data *data)
{
	int	id;

	data->stack_a = data->start_stack_a;
	if (data->stack_a)
	{
		id = 0;
		while (data->stack_a)
		{
			if (data->stack_a->id == id)
				id++;
			else
				return (1);
			data->stack_a = data->stack_a->next;
		}
	}
	data->stack_a = data->start_stack_a;
	return (0);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac >= 2)
	{
		if (ft_checkint(av) || ft_check_int(ac, av) || ft_check_null(ac, av))
			return (0);
		has_sign_but_no_nbr(ac, av);
		data = ft_initial_data(ac, av);
		if (!data)
		{
			ft_free(&data);
			exit (1);
		}
		ft_putid(&data);
		if (ft_sort(&data))
		{
			ft_free(&data);
			exit(1);
		}
		ft_free(&data);
	}
}
