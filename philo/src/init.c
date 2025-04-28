/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:21:12 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/28 16:57:04 by ghambrec         ###   ########.fr       */
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
	table->philos_finished = false;
	pthread_mutex_init(&table->mutex_philo_died, NULL);
	pthread_mutex_init(&table->mutex_philos_finished, NULL);
}

static void	init_philos(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->chairs)
	{
		table->philo[i].id = i + 1;
		pthread_mutex_init(&table->philo[i].fork_left, NULL);
		if (i != 0)
			table->philo[i].fork_right = &table->philo[i - 1].fork_left;
		if (i == table->chairs - 1)
			table->philo[i].fork_right = &table->philo[0].fork_left;
		table->philo[i].last_meal = ft_get_current_ms(table);
		table->philo[i].meals_eaten = 0;
		pthread_mutex_init(&table->philo[i].mutex_last_meal, NULL);
		i++;
	}	
}

// static void	init_forks(t_table *table)
// {
	
// }

void	init_structs(t_table *table, int argc, char **argv)
{
	init_table(table, argc, argv);
	init_philos(table);
	// init_forks(table);
}