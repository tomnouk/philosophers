/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:01:37 by anomourn          #+#    #+#             */
/*   Updated: 2024/07/08 12:29:40 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*initialisation data struct*/
t_data	*init_data(char **s, int size)
{
	t_data	*data;
	int		i;

	i = 0;
	data = malloc(sizeof(t_data) * 1);
	if (!data)
		return (NULL);
	data->nb_philo = ft_atoi(s[1]);
	data->time_to_die = ft_atoi(s[2]);
	data->time_to_eat = ft_atoi(s[3]);
	data->time_to_sleep = ft_atoi(s[4]);
	if (size == 5)
		data->max_meals = -1;
	else
		data->max_meals = ft_atoi(s[5]);
	data->enough_meals = 0;
	data->finish = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (NULL);
	while (i < data->nb_philo)
		pthread_mutex_init(&data->forks[i++], NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->meals, NULL);
	return (data);
}

void	init_philo(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		philo->t_after_eat = 0;
		philo->nb_eat = 0;
		philo[i].data = data;
		philo[i].id = i + 1;
		pthread_mutex_init(&philo[i].time, NULL);
		i++;
	}
}
