/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:35:32 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 14:06:28 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *philo_ptr)
{
	t_philos	*philo;
	
	philo = (t_philos *)philo_ptr;
	printf("Ich bin Philo %i\n", philo->id);
	return (NULL);
}

void	create_philos(t_table *table)
{
	int			i;
	t_philos	*philo;

	i = 0;
	while (i < table->chairs)
	{
		philo = &table->philo[i];
		pthread_create(&philo->thread, NULL, philo_routine, (void*) philo);
		i++;
		usleep(2000);
	}
}

int	start_dining(t_table *table)
{
	// Fehlerhandling fuer create_threads noch einbauen?
	create_philos(table);
	// start_monitor(table);

	return (EXIT_SUCCESS);
}