/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 15:24:51 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/06 15:54:32 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup(t_table *table)
{
	int	i;

	pthread_mutex_destroy(&table->mutex_philo_died);
	pthread_mutex_destroy(&table->mutex_printf);
	i = 0;
	while (i < table->chairs)
	{
		pthread_mutex_destroy(&table->philo[i].fork_left);
		pthread_mutex_destroy(&table->philo[i].mutex_last_meal);
		pthread_mutex_destroy(&table->philo[i].mutex_philo_full);
		i++;
	}
}
