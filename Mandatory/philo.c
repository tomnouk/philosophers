/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:57 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/07/11 10:59:04 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/* print the elapsed time, the id of the philo and the action he is doing */
void	ft_print_philo(t_data *data, char *str, int id)
{
	pthread_mutex_lock(&data->print);
	printf("%lld %d %s", ft_time() - data->start, id, str);
	pthread_mutex_unlock(&data->print);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (!ft_check_arg(argv, argc))
		return (0);
	data = init_data(argv, argc);
	if (!data)
		return (0);
	ft_create_philo(data);
	free_and_destroy(data);
}
