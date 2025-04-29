/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 13:56:40 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 22:22:33 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	join_philos(t_table *table)
{
	int			i;

	i = 0;
	while (i < table->chairs)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
}

// void	join_monitor(t_table *table)
// {
// 	pthread_join(table->monitor, NULL);
// }
