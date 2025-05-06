/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:51:46 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/06 17:09:19 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_think(t_philos *philo)
{
	print_action(philo, "is thinking");
	if (philo->table->chairs % 2 != 0 && philo->meals_eaten != 0)
		usleep(100);
}
