/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:21:12 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/30 00:59:24 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_table(t_table *table, int argc, char **argv)
{
	table->chairs = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		table->max_meals = ft_atoi(argv[5]);
	table->start_time = ft_gettimeofday_ms();
	table->philo_died = false;
	pthread_mutex_init(&table->mutex_philo_died, NULL);
	pthread_mutex_init(&table->mutex_printf, NULL);
}

static void	init_philos(t_table *table)
{
	int			i;
	t_philos	*philo;

	i = 0;
	while (i < table->chairs)
	{
		philo = &table->philo[i];
		philo->id = i + 1;
		pthread_mutex_init(&philo->fork_left, NULL);
		if (i == 0)
			philo->fork_right = &table->philo[table->chairs - 1].fork_left;
		else
			philo->fork_right = &table->philo[i - 1].fork_left;
		philo->last_meal = ft_get_current_ms(table);
		philo->meals_eaten = 0;
		philo->philo_dead = false;
		pthread_mutex_init(&philo->mutex_philo_full, NULL);
		pthread_mutex_init(&philo->mutex_philo_dead, NULL);
		philo->table = table;
		i++;
	}	
}

void	init_structs(t_table *table, int argc, char **argv)
{
	init_table(table, argc, argv);
	init_philos(table);
}
