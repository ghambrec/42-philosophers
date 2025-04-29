/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:56:40 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 23:40:57 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_philos(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->chairs)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}

static void	join_monitor(t_table *table)
{
	pthread_join(table->monitor, NULL);
}

void	join_threads(t_table *table)
{
	join_philos(table);
	join_monitor(table);
}
