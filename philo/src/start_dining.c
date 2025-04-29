/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:35:32 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 23:41:04 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_philos(t_table *table)
{
	int			i;
	t_philos	*philo;

	i = 0;
	while (i < table->chairs)
	{
		philo = &table->philo[i];
		pthread_create(&philo->thread, NULL, routine_philo, (void*) philo);
		i++;
	}
}

static void	create_monitor(t_table *table)
{
	usleep(200);
	pthread_create(&table->monitor, NULL, routine_monitor, (void*) table);
}

int	start_dining(t_table *table)
{
	// Fehlerhandling fuer create_threads noch einbauen?
	create_philos(table);
	create_monitor(table);
	return (EXIT_SUCCESS);
}