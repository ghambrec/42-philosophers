/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:24:47 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 22:48:27 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_full(t_philos *philo)
{
	int	i_am_full;
	pthread_mutex_lock(&philo->mutex_philo_full);
	i_am_full = philo->philo_full;
	pthread_mutex_unlock(&philo->mutex_philo_full);
	return (i_am_full);
}

int	is_dead(t_philos *philo)
{
	int	i_am_dead;
	pthread_mutex_lock(&philo->mutex_philo_dead);
	i_am_dead = philo->philo_dead;
	pthread_mutex_unlock(&philo->mutex_philo_dead);
	return (i_am_dead);
}

int	is_dead_one(t_table *table)
{
	int	one_dead;
	pthread_mutex_lock(&table->mutex_philo_died);
	one_dead = table->philo_died;
	pthread_mutex_unlock(&table->mutex_philo_died);
	return (one_dead);
}

void	print_action(t_philos *philo, char *action)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->mutex_printf);
	printf("%zu %i %s\n", ft_get_current_ms(table), philo->id, action);
	pthread_mutex_unlock(&table->mutex_printf);
}
