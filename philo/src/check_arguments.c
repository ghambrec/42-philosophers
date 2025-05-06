/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:30:03 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/06 18:02:45 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	print_err(char *error_msg)
{
	ft_putstr_fd("Invalid input - ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
}

static int	contains_only_numbers(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		print_err("Wrong amount of arguments!");
		return (1);
	}
	i = 1;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) <= 0)
		{
			print_err("Only numbers bigger than 0 allowed!");
			return (1);
		}
		if (contains_only_numbers(argv[i]) == FALSE)
		{
			print_err("Only numbers allowed!");
			return (1);
		}
		if (i == 1 && ft_atoi(argv[i]) > MAX_PHILOS)
			return (print_err("Max philo is 200"), 1);
		i++;
	}
	return (0);
}
