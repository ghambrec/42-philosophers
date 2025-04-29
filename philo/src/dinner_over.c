/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner_over.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 22:29:54 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 22:51:51 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



// dinner_over_philo (for a single philo)
// a) some philo died
// b) this philo is full
int	dinner_over_philo(t_philos *philo)
{
	if (is_dead_one(philo->table) == true || is_full(philo) == true)
		return (true);
	return (false);
}


// dinner_over_monitor (for monitor)
// a) some philo died
// b) all philos are full
