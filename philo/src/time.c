/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:44:17 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/06 17:05:01 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_gettimeofday_ms(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (0);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

size_t	ft_get_current_ms(t_table *table)
{
	return (ft_gettimeofday_ms() - table->start_time);
}

void	super_sleep(size_t ms, t_philos *philo)
{
	size_t	start;

	start = ft_gettimeofday_ms();
	while ((ft_gettimeofday_ms() - start) < ms && is_dead_one(philo->table) == false)
		usleep(500);
}
