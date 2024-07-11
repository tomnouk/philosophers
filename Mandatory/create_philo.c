/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:42:19 by anomourn          #+#    #+#             */
/*   Updated: 2024/07/11 10:57:11 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* check if the has finished eating */
void	check_food(t_data *data, t_philo *philo)
{
	if (data->max_meals != -1)
	{
		pthread_mutex_lock(&philo->data->meals);
		if (philo->nb_eat == data->max_meals)
			data->enough_meals++;
		if (data->enough_meals == data->nb_philo)
		{
			pthread_mutex_lock(&philo->data->death);
			data->finish = 1;
			pthread_mutex_unlock(&philo->data->death);
		}
		pthread_mutex_unlock(&philo->data->meals);
	}
}

/* eating process */
void	ft_eating(t_data *data, t_philo *philo, int id, int sec)
{
	ft_print_philo(data, FORK, id);
	ft_print_philo(data, EAT, id);
	ft_usleep(data->time_to_eat);
	pthread_mutex_lock(&philo->time);
	philo->t_after_eat = ft_time();
	philo->nb_eat++;
	pthread_mutex_unlock(&philo->time);
	check_food(data, philo);
	pthread_mutex_unlock(&data->forks[id - 1]);
	pthread_mutex_unlock(&data->forks[sec]);
}

int	ft_food_philo(t_philo *philo, t_data *data, int id)
{
	int	sec_fork;

	sec_fork = ind_sec_fork(data, id);
	pthread_mutex_lock(&data->forks[id - 1]);
	if (check_mort_finish(data))
	{
		pthread_mutex_unlock(&data->forks[id - 1]);
		return (0);
	}
	ft_print_philo(data, FORK, id);
	if (data->nb_philo == 1)
	{
		pthread_mutex_unlock(&data->forks[id - 1]);
		return (0);
	}
	pthread_mutex_lock(&data->forks[sec_fork]);
	if (check_mort_finish(data))
	{
		pthread_mutex_unlock(&data->forks[id - 1]);
		pthread_mutex_unlock(&data->forks[sec_fork]);
		return (0);
	}
	ft_eating(data, philo, id, sec_fork);
	return (1);
}

void	*ft_thread_philo(void *args)
{
	t_philo	*philo;
	t_data	*data;
	int		id;

	philo = (t_philo *)args;
	data = philo->data;
	id = philo->id;
	if (id % 2 != 0)
		ft_usleep(50);
	pthread_mutex_lock(&philo->time);
	philo->nb_eat = 0;
	pthread_mutex_unlock(&philo->time);
	while (1)
	{
		if (data->max_meals == 0 || ft_food_philo(philo, data, id) == 0)
			break ;
		if (check_mort_finish(data))
			return (0);
		ft_print_philo(data, SLEEP, id);
		ft_usleep(data->time_to_sleep);
		if (check_mort_finish(data))
			break ;
		ft_print_philo(data, THINK, id);
	}
	return (NULL);
}

void	ft_create_philo(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = ft_calloc(sizeof(t_philo), data->nb_philo + 1);
	if (!philo)
		return ;
	data->tid = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->tid)
		return ;
	data->philo = philo;
	data->start = ft_time();
	pthread_mutex_init(&data->print, NULL);
	init_philo(data, philo);
	while (i < data->nb_philo)
	{
		philo[i].t_after_eat = ft_time();
		pthread_create(&data->tid[i], NULL, &ft_thread_philo, &philo[i]);
		i++;
	}
	ft_check_death(data, philo);
	i = 0;
	while (i < data->nb_philo)
		pthread_join(data->tid[i++], NULL);
}
