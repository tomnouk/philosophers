/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:23:53 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/06/20 14:49:44 by anomourn         ###   ########.fr       */
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