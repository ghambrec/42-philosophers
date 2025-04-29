/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 21:42:43 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 22:22:17 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// static int	check_philo_dead(t_philos *philo)
// {
// 	int	is_dead;

// 	pthread_mutex_lock(&philo->mutex_philo_dead);
// 	is_dead = philo->philo_dead;
// 	pthread_mutex_unlock(&philo->mutex_philo_dead);
// 	return (is_dead);
// }

// static int	check_philo_full(t_philos *philo)
// {
// 	int	meals_eaten;
	
// 	pthread_mutex_lock(&philo->mutex_meals_eaten);
// 	meals_eaten = philo->meals_eaten;
// 	pthread_mutex_unlock(&philo->mutex_meals_eaten);
// 	if (meals_eaten == philo->table->max_meals)
// 		return (true);
// 	return (false);
// }

// void	*routine_monitor(void *table_ptr)
// {
// 	int		i;
// 	t_table	*table;

// 	table = (t_table*)table_ptr;
// 	while (true)
// 	{
// 		i = 0;
// 		while (i < table->chairs)
// 		{
// 			if (check_philo_dead(&table->philo[i]) == true)
// 			{
// 				pthread_mutex_lock(&table->mutex_philo_died);
// 				table->philo_died = true;
// 				pthread_mutex_unlock(&table->mutex_philo_died);
// 				return (NULL);
// 			}
// 			i++;
// 		}
// 		usleep(100);
// 	}
// 	return (NULL);
// }