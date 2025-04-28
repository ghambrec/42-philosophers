/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:53:42 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/28 17:28:34 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_arguments(argc, argv) != 0)
		return (EXIT_FAILURE);
	init_structs(&table, argc, argv);
	if (create_philos(&table) != 0) // mit der funktion weitermachen
	{
		ft_putendl_fd("Error creating philo-threads\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	// fuer monitor noch separate pthread_t in table struct 
	
	return (EXIT_SUCCESS);
}