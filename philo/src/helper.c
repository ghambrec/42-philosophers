/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 14:24:47 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/29 15:06:40 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dinner_over(t_table *table)
{
	int	philo_died;
	int	dinner_finished;

	pthread_mutex_lock(&table->mutex_philo_died);
	philo_died = table->philo_died;
	pthread_mutex_unlock(&table->mutex_philo_died);
	pthread_mutex_lock(&table->mutex_dinner_finished);
	dinner_finished = table->dinner_finished;
	pthread_mutex_unlock(&table->mutex_dinner_finished);
	if (philo_died == true || dinner_finished == true)
		return (true);
	return (false);
}

void	print_action(t_philos *philo, char *action)
{
	t_table	*table;

	table = philo->table;
	pthread_mutex_lock(&table->mutex_printf);
	printf("%zu %i %s\n", ft_get_current_ms(table), philo->id, action);
	pthread_mutex_unlock(&table->mutex_printf);
}
