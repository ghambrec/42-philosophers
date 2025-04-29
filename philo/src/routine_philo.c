/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:44:31 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/30 00:48:30 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_alive(t_philos *philo)
{
	size_t	time_to_die;

	time_to_die = philo->table->time_to_die;
	if (ft_get_current_ms(philo->table) - philo->last_meal >= time_to_die)
		return (false);
	return (true);
}

static void	set_philo_dead(t_philos *philo)
{
	pthread_mutex_lock(&philo->mutex_philo_dead);
	philo->philo_dead = true;
	pthread_mutex_unlock(&philo->mutex_philo_dead);
}

static int	call_action(void (*action)(t_philos *), t_philos *philo)
{
	if (dinner_over_philo(philo) == true)
		return (false);
	if (check_philo_alive(philo) == true)
		action(philo);
	else
	{
		set_philo_dead(philo);
		return (false);
	}
	return (true);
}

void	*routine_philo(void *philo_ptr)
{
	t_philos	*philo;
	
	philo = (t_philos *)philo_ptr;
	while (dinner_over_philo(philo) == false)
	{
		if (call_action(p_think, philo) == false)
			return (NULL);
		if (call_action(p_eat, philo) == false)
			return (NULL);
		if (call_action(p_sleep, philo) == false)
			return (NULL);
	}
	return (NULL);
}
