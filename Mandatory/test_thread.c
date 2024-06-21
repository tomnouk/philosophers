/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:51:09 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/21 16:43:48 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*print_coucou(void *arg)
{
	int i = 0;
	while (i < 100)
	{
		printf("coucou\n");
		i++;
		usleep(10000);
	}
	return NULL;
}

void	*print_hello(void *arg)
{
	int i = 0;
	while (i < 100)
	{
		printf("\t\thello\n");
		i++;
		usleep(10000);
	}
	return NULL;
}

void	test()
{
	pthread_t t1;
	pthread_t t2; 
	
	if (pthread_create(&t1, NULL, print_coucou, NULL))
		exit(1);
	if (pthread_create(&t2, NULL, print_hello, NULL))
		exit(1);
	if (pthread_join(t1, NULL))
		exit(1);
	if (pthread_join(t2, NULL))
		exit(1);
}

void	*routine(void *arg)
{
	int *num;
	int i;
	num = (int *)arg;
	while(i < 100) //for data race
	{
		(*num)++;
		i++;
	}
	return NULL;
}

void	test_2()
{
	int *num;
	pthread_t t1;
	pthread_t t2;

	num = malloc(sizeof(int));
	if (!num)
		exit(1);
	*num = 0;
	if (pthread_create(&t1, NULL, routine, num))
		exit(1);
	if (pthread_create(&t2, NULL, routine, num))
		exit(1);
	if (pthread_join(t1, NULL))
		exit(1);
	if (pthread_join(t2, NULL))
		exit(1);
	printf("num = %d\n", *num);
}

// int main()
// {
// 	test();
// 	return (0);
// }