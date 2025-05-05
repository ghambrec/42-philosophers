/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:44:31 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/05 16:09:39 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	call_action(void (*action)(t_philos *), t_philos *philo)
{
	if (dinner_over(philo) == true)
		return (false);
	action(philo);
	return (true);
}

void	*routine_philo(void *philo_ptr)
{
	t_philos	*philo;
	
	philo = (t_philos *)philo_ptr;
	if (philo->id % 2 != 0)
		usleep(1000);
	while (dinner_over(philo) == false)
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

void	*routine_only_one_philo(void *philo_ptr)
{
	t_philos	*philo;
	
	philo = (t_philos *)philo_ptr;
	call_action(p_think, philo);
	pthread_mutex_lock(&philo->fork_left);
	print_action(philo, "took a fork");
	super_sleep(philo->table->time_to_die);
	pthread_mutex_unlock(&philo->fork_left);
	return (NULL);

	// todo diesen case testen
}