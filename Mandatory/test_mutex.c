/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:37:23 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/21 14:28:42 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

typedef struct	data_s
{
	int num;
	pthread_mutex_t mutex;
}				data_t;

data_t	*init_data()
{
	data_t *data;
	data = malloc(sizeof(data_t));
	if (!data)
		exit(1);
	data->num = 0;
	pthread_mutex_init(&data->mutex, NULL);
	return (data);
}

void free_data(data_t *data)
{
	pthread_mutex_destroy(&data->mutex);
	free(data);
}

void *routine_2(void *arg)
{
	data_t *data;
	int i;

	data = (data_t *)arg;
	i = 0;
	while (i < 10000)
	{
		pthread_mutex_lock(&data->mutex);
		data->num++;
		pthread_mutex_unlock(&data->mutex);
		i++;
	}
	return (NULL);

}

void ex1()
{
	data_t *data;
	pthread_t t1;
	pthread_t t2;

	data = init_data();
	if (pthread_create(&t1, NULL, routine_2, data))
		exit(1);
	if (pthread_create(&t2, NULL, routine_2, data))
		exit(1);
	if (pthread_join(t1, NULL))
		exit(1);
	if (pthread_join(t2, NULL))
		exit(1);
	printf("num = %d\n", data->num);
	free_data(data);
}

int main()
{
	ex();
	return (0);
}




