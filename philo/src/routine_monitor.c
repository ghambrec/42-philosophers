/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:42:43 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/30 00:47:16 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_died(t_philos *philo)
{
	pthread_mutex_lock(&philo->table->mutex_philo_died);
	philo->table->philo_died = true;
	pthread_mutex_unlock(&philo->table->mutex_philo_died);
	pthread_mutex_lock(&philo->table->mutex_printf);
	printf("%zu %i %s\n", ft_get_current_ms(philo->table), philo->id, "died");
	pthread_mutex_unlock(&philo->table->mutex_printf);
}

void	*routine_monitor(void *table_ptr)
{
	int		i;
	t_table	*table;

	table = (t_table*)table_ptr;
	while (true)
	{
		i = 0;
		while (i < table->chairs)
		{
			if (is_dead(&table->philo[i]))
			{
				philo_died(&table->philo[i]);
				return (NULL);
			}
			i++;
		}
		usleep(500);
	}
	return (NULL);
}
