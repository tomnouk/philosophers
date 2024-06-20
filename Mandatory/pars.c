/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukmournard <anoukmournard@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:53 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/19 12:27:51 by anoukmourna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_digital(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	if (i == 0 || s[0] == '0')
		return (0);
	return (1);
}

//nb de philo max == 200
//nb de repas peut etre == 0