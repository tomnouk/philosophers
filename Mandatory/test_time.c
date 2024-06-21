/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:08:20 by anomourn          #+#    #+#             */
/*   Updated: 2024/06/21 16:30:43 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	ex_time()
{
	struct timeval time;

	if (gettimeofday(&time, NULL))
		exit(1);
	printf("time sec: %ld\n", time.tv_sec);
	printf("time microsec: %ld\n", time.tv_usec);
	printf("years passed since 1980: %ld\n", time.tv_sec / 60 / 60 / 24 / 365);
}

uint64_t	get_time(void) //convert in ms
{
	struct	timeval tv;

	if (gettimeofday(&tv, NULL))
		exit(1);
	return (tv.tv_sec * (uint64_t)1000 + tv.tv_usec / 1000);
}

void	ex_time2()
{
	uint64_t start_time;
	uint64_t now;
	
	start_time = get_time();
	usleep(100000);
	now = get_time();
	printf("milliseconds passed: %ld\n", now - start_time);
}

// int main()
// {
// 	//ex_time();
// 	ex_time2();
// 	return (0);
// }

