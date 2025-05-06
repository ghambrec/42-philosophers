/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:30:03 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/06 17:10:55 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	contains_only_numbers(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

int	check_arguments(int argc, char **argv)
{
	int	i;
	if (argc < 5 || argc > 6)
	{
		ft_putendl_fd("Invalid input - Wrong number of arguments!", STDERR_FILENO);
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			ft_putendl_fd("Invalid input - Only numbers bigger than 0 allowed!", STDERR_FILENO);
			return (1);
		}
		if (contains_only_numbers(argv[i]) == false)
		{
			ft_putendl_fd("Invalid input - Only numbers allowed!", STDERR_FILENO);
			return (1);
		}
		if (i == 1 && ft_atoi(argv[i]) > MAX_PHILOS)
			return (ft_putendl_fd("Invalid input - Max philo is 200", STDERR_FILENO), 1);
		i++;
	}
	return (0);
}
