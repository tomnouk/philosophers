/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:12:25 by anomourn          #+#    #+#             */
/*   Updated: 2024/07/11 10:44:48 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_mort_finish(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->death);
	i = data->finish;
	pthread_mutex_unlock(&data->death);
	return (i);
}

int	philo_mort(t_philo *philo)
{
	t_data	*data;
	int		i;

	i = 0;
	data = philo->data;
	pthread_mutex_lock(&data->death);
	if (data->finish != 1)
	{
		pthread_mutex_lock(&philo->time);
		if ((philo->nb_eat != data->max_meals)
			&& (ft_time() - philo->t_after_eat) > (u_int64_t)data->time_to_die)
		{
			data->finish = 1;
			ft_print_philo(data, DEAD, philo->id);
		}
		pthread_mutex_unlock(&philo->time);
	}
	i = data->finish;
	pthread_mutex_unlock(&data->death);
	return (i);
}

void	ft_check_death(t_data *data, t_philo *philo)
{
	int	i;

	if (data->max_meals != 0 && data->nb_philo != 0)
	{
		while (1)
		{
			i = 0;
			while (i < data->nb_philo)
			{
				if (philo_mort(&philo[i]))
					break ;
				i++;
			}
			if (i != data->nb_philo)
				break ;
		}
	}
}
