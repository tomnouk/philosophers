/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:09:36 by anomourn          #+#    #+#             */
/*   Updated: 2024/07/10 15:23:12 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_is_digit(char **s, int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (s[i][j])
		{
			if ((s[i][j] < '0' || s[i][j] > '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_limit_arg(char **s, int size)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if (ft_atoi(s[i]) == -1 || ft_atoi(s[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_arg(char **s, int size)
{
	if (size < 5 || size > 6)
	{
		printf("%s", ARG_ERROR);
		return (0);
	}
	if (!ft_is_digit(s, size))
	{
		printf("%s", DIGIT_ERROR);
		return (0);
	}
	if (!ft_limit_arg(s, size))
	{
		printf("%s", DIGIT_ERROR);
		return (0);
	}
	if (size == 6 && ft_atoi(s[5]) == 0)
	{
		printf("%s", NB_MUST_EAT);
		return (0);
	}
	return (1);
}

void	free_and_destroy(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = data->philo;
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->meals);
	while (i < data->nb_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&philo[i].time);
		i++;
	}
	free(philo);
	free(data->forks);
	free(data->tid);
	free(data);
}
