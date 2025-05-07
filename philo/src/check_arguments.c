/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 13:30:03 by ghambrec          #+#    #+#             */
/*   Updated: 2025/05/07 12:11:07 by ghambrec         ###   ########.fr       */
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
		return (print_err("Wrong amount of arguments!"), 1);
	i = 1;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) > 10)
			return (print_err("Number too big!"), 1);
		if (ft_atol(argv[i]) < -2147483648 || ft_atol(argv[i]) > 2147483647)
			return (print_err("Number out of int range!"), 1);
		if (ft_atoi(argv[i]) <= 0)
			return (print_err("Only numbers bigger than 0 allowed!"), 1);
		if (contains_only_numbers(argv[i]) == FALSE)
			return (print_err("Only numbers allowed!"), 1);
		if (i == 1 && ft_atoi(argv[i]) > MAX_PHILOS)
			return (print_err("Max philo is 200"), 1);
		i++;
	}
	return (0);
}
