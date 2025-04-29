/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:13:44 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/30 00:31:52 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philos *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_right);
		pthread_mutex_lock(&philo->fork_left);
	}
	else
	{
		pthread_mutex_lock(&philo->fork_left);
		pthread_mutex_lock(philo->fork_right);
	}
}

static void	release_forks(t_philos *philo)
{
	pthread_mutex_unlock(&philo->fork_left);
	pthread_mutex_unlock(philo->fork_right);
}

// increase eaten meals / set flag philo_full if he ate enough / set last meal
static void	eat_spaghetti(t_philos *philo)
{
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->table->max_meals)
	{
		pthread_mutex_lock(&philo->mutex_philo_full);
		philo->philo_full = true;
		pthread_mutex_unlock(&philo->mutex_philo_full);
	}
	philo->last_meal = ft_get_current_ms(philo->table);
	print_action(philo, "is eating");
	super_sleep(philo->table->time_to_eat);
}

void	p_eat(t_philos *philo)
{
	take_forks(philo);
	eat_spaghetti(philo);
	release_forks(philo);
}
