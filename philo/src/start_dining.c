/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dining.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:35:32 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/06 17:58:54 by ghambrec         ###   ########.fr       */
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
		pthread_create(&philo->thread, NULL, routine_philo, (void *)philo);
		i++;
	}
}

static void	create_only_one_philo(t_table *table)
{
	pthread_create(&table->philo[0].thread, NULL, \
		routine_only_one_philo, (void *)&table->philo);
}

static void	create_monitor(t_table *table)
{
	usleep(200);
	pthread_create(&table->monitor, NULL, routine_monitor, (void *)table);
}

void	start_dining(t_table *table)
{
	if (table->chairs == 1)
		create_only_one_philo(table);
	else
		create_philos(table);
	create_monitor(table);
}
