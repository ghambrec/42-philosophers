/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:42:43 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/05 16:09:32 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	all_full(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->chairs)
	{
		if (is_full(&table->philo[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static int	philo_died(t_philos *philo)
{
	size_t	last_meal;

	pthread_mutex_lock(&philo->mutex_last_meal);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->mutex_last_meal);
	if (ft_get_current_ms(philo->table) - last_meal >= philo->table->time_to_die)
		return (true);
	return (false);
}

static void	set_philo_died(t_philos *philo)
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
			if (philo_died(&table->philo[i]) == true)
			{
				set_philo_died(&table->philo[i]);
				return (NULL);
			}
			if (all_full(table) == true)
				return (NULL);
			i++;
		}
		usleep(500);
	}
	return (NULL);
}
