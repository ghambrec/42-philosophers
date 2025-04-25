/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghambrec <ghambrec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:13:31 by ghambrec          #+#    #+#             */
/*   Updated: 2025/04/25 18:59:50 by ghambrec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// weil stdlib nicht inkludiert ist
# define	EXIT_FAILURE 1
# define	EXIT_SUCCESS 0

// unnoetige includes wieder loeschen
# include <stdio.h> // printf
# include <pthread.h> // thread
# include <unistd.h> // usleep


// ---------------------------------------------
// UTILS
// ---------------------------------------------
int		ft_atoi(const char *str);
int		ft_isdigit(int num);
char	*ft_strchr(const char *str, int c);
void	ft_putendl_fd(char *s, int fd);

#endif