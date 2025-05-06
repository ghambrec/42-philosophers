/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:13:31 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/06 19:18:27 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define EXIT_FAILURE	1
# define EXIT_SUCCESS	0
# define TRUE	1
# define FALSE	0
# define MAX_PHILOS	200

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	*fork_right;
	size_t			last_meal;
	int				meals_eaten;
	int				philo_full;
	pthread_mutex_t	mutex_last_meal;
	pthread_mutex_t	mutex_philo_full;
	struct s_table	*table;
}	t_philos;

typedef struct s_table
{
	int				chairs;
	pthread_t		monitor;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				max_meals;
	int				philo_died;
	pthread_mutex_t	mutex_philo_died;
	pthread_mutex_t	mutex_printf;
	t_philos		philo[MAX_PHILOS];
}	t_table;

// ---------------------------------------------
// PHILOSOPHERS
// ---------------------------------------------
int		check_arguments(int argc, char **argv);
void	init_structs(t_table *table, int argc, char **argv);
size_t	ft_gettimeofday_ms(void);
size_t	ft_get_current_ms(t_table *table);
void	start_dining(t_table *table);
void	join_threads(t_table *table);
int		dinner_over(t_philos *philo);
void	*routine_philo(void *philo_ptr);
void	print_action(t_philos *philo, char *action);
void	p_think(t_philos *philo);
void	p_sleep(t_philos *philo);
void	p_eat(t_philos *philo);
void	*routine_monitor(void *table_ptr);
int		is_full(t_philos *philo);
int		is_dead_one(t_table *table);
void	super_sleep(size_t ms);
void	*routine_only_one_philo(void *philo_ptr);
void	cleanup(t_table *table);

// ---------------------------------------------
// UTILS
// ---------------------------------------------
int		ft_atoi(const char *str);
int		ft_isdigit(int num);
char	*ft_strchr(const char *str, int c);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);

#endif
