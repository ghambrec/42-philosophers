/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:53:42 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 14:45:42 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_arguments(argc, argv) != 0)
		return (EXIT_FAILURE);
	init_structs(&table, argc, argv);
	if (start_dining(&table) != 0)
	{
		ft_putendl_fd("Error starting the simulation\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	join_philos(&table);
	// fuer monitor noch separate pthread_t in table struct 
	
	return (EXIT_SUCCESS);
}