/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:53:42 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/28 16:26:14 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (check_arguments(argc, argv) != 0)
		return (EXIT_FAILURE);
	init_structs(&table, argc, argv);

	

	return (EXIT_SUCCESS);
}