/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:24:00 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/21 14:17:42 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

# define ARG_ERROR "Number of arguments is invalid.\n"
# define DIGIT_ERROR "Arguments must be digits.\n"

int	check_digital(char *s);
void *routine(void *arg);

#endif