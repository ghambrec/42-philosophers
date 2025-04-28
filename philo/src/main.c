/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 18:53:42 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/28 13:31:19 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	if (check_arguments(argc, argv) != 0)
		return (EXIT_FAILURE);	

	printf("passt!\n");

	return (EXIT_SUCCESS);
}