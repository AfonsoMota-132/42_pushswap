/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afogonca <afogonca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 09:00:29 by afogonca          #+#    #+#             */
/*   Updated: 2024/12/04 09:02:42 by afogonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_trim_args(int argc, char **argv)
{
	int		i;
	char	**trimmed;

	trimmed = (char **)malloc(sizeof(char *) * (argc + 1));
	if (!trimmed)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		trimmed[i] = ft_strtrim(argv[i], " ");
		i++;
	}
	trimmed[i] = NULL;
	return (trimmed);
}

/*int	main(int ac, char **av)*/
/*{*/
/*	av = ft_trim_args(ac, av);*/
/*	if (av)*/
/*	{*/
/*		while (*av)*/
/*			printf("%s\n", *av++);*/
/*	}*/
/*	return (0);*/
/*}*/
