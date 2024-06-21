/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:24:00 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/21 16:46:45 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

# define THINK "is thiking\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define FORK "has taken a fork\n"
# define DEAD "died\n"

# define ARG_ERROR "Number of arguments is invalid.\n"
# define DIGIT_ERROR "Arguments must be digits.\n"

typedef	struct	s_philo
{
	int				id;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				*forks;
	int 			*thread_philo;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*print;
	pthread_mutex_t	*death;
	struct timeval	start;
	struct timeval	last_meal;
}				t_philo;

int	check_digital(char *s);

void	*routine(void *arg);

// utils.c
int	ft_atoi(char	*str);

#endif