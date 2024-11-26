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

int	check_int(int ac, char **av)
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
