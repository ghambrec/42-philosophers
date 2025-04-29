/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 15:12:07 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/30 00:31:37 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_sleep(t_philos *philo)
{
		print_action(philo, "is sleeping");
		super_sleep(philo->table->time_to_sleep);
}
