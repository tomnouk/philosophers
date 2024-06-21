/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:57 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/21 16:48:18 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init_struct(t_philo *philo, char **argv)
{
    philo->nb_philo = ft_atoi(argv[1]);
    philo->time_to_die = ft_atoi(argv[2]);
    philo->time_to_eat = ft_atoi(argv[3]);
    philo->time_to_sleep = ft_atoi(argv[4]);
    if (argv[5])
        philo->nb_meals = ft_atoi(argv[5]);
    else
        philo->nb_meals = 0;
}

void init_philo(t_philo *philo)
{
    int i;

    i = 0;
    philo->thread_philo = malloc(sizeof(t_philo) * philo->nb_philo);
    if (!philo->thread_philo)
        exit(1);
    while (i < philo->nb_philo)
    {
        printf("philo %d\n", i);
        i++;
    }
}

int	main (int argc, char **argv)
{
	int i;
    t_philo philo;

	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (i < argc)
		{
			if (!check_digital(argv[i]))
			{
				printf("ERROR - %s", DIGIT_ERROR);
				return (0);
			}
            else 
            {
                init_struct(&philo, argv);
                init_philo(&philo);
            }
            
			i++;
		}
	}
	else
		printf("ERROR - %s", ARG_ERROR);
	return (0);
}

