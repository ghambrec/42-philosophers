/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:53:42 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/25 19:06:27 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_arguments(int argc, char **argv)
{
	int	i;
	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Invalid number of arguments!", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	i = 1;
	while (argv[i])
	{ // kleiner 0 oder kleiner gleich 0 ??? deckel aus eval sheet mit einbauen??
		if (ft_atoi(argv[i]) < 0)
		{
			ft_putendl_fd("Only positive numbers allowed!", STDERR_FILENO);
		}
	}
}

int	main(int argc, char **argv)
{
	if (check_arguments(argc, argv) != 0)
		return (EXIT_FAILURE);	


	return (EXIT_SUCCESS);
}