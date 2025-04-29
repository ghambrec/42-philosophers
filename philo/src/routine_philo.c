/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:44:31 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 15:09:24 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine_philo(void *philo_ptr)
{
	t_philos	*philo;
	
	philo = (t_philos *)philo_ptr;
	while (dinner_over(philo->table) == false)
	{
		// think, eat (takefork), sleep
		think(philo);
		eat(philo);
		return (NULL);
	}

	
	return (NULL);
}
