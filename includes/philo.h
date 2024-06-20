/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:24:00 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/19 12:07:09 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>

# define ARG_ERROR "Number of arguments is invalid.\n"
# define DIGIT_ERROR "Arguments must be digits.\n"

int	check_digital(char *s);

#endif