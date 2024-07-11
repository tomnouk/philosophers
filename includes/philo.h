/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anomourn <anomourn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 11:24:00 by anoukmourna       #+#    #+#             */
/*   Updated: 2024/07/11 11:01:51 by anomourn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <time.h>
# include <sys/types.h>

# define THINK "\e[0;36mis thiking\n\e[0m"
# define EAT "\e[0;32mis eating\n\e[0m"
# define SLEEP "\e[0;33mis sleeping\n\e[0m"
# define FORK "\e[0;34mhas taken a fork\n\e[0m"
# define DEAD "\e[1;31mis died\n\e[0m"

# define ARG_ERROR "\e[0;35mERROR ~ Number of arguments is invalid :( \n\e[0m"
# define DIGIT_ERROR "\e[0;35mERROR ~ Arguments must be digits :( \n\e[0m"
# define NB_MUST_EAT "\e[0;35mERROR: Nb of meals must be greather than 0\n\e[0m"

typedef struct s_data
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				max_meals;
	int				enough_meals;
	int				finish;
	struct s_philo	*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death;
	pthread_mutex_t	meals;
	pthread_mutex_t	print;
	pthread_t		*tid;
	long long		start;
}			t_data;

typedef struct s_philo
{
	struct s_data	*data;
	int				id;
	int				nb_eat;
	long long		t_after_eat;
	pthread_mutex_t	time;

}				t_philo;

/*init_all*/
void		ft_print_philo(t_data *data, char *str, int id);
t_data		*init_data(char **s, int size);
void		init_philo(t_data *data, t_philo *philo);

/*pars*/
int			ft_is_digit(char **s, int size);
int			ft_limit_arg(char **s, int size);
int			ft_check_arg(char **s, int size);
void		free_and_destroy(t_data *data);

/*utils*/
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t count, size_t size);
int			ft_strlen(char *str);
int			ft_atoi(char *str);
int			ind_sec_fork(t_data *data, int id);

/*death*/
int			check_mort_finish(t_data *data);
int			philo_mort(t_philo *philo);
void		ft_check_death(t_data *data, t_philo *philo);

/*time*/
u_int64_t	ft_time(void);
int			ft_usleep(__useconds_t time);

/*create_philo*/
void		check_food(t_data *data, t_philo *philo);
void		ft_eating(t_data *data, t_philo *philo, int id, int sec);
int			ft_food_philo(t_philo *philo, t_data *data, int id);
void		*ft_thread_philo(void *args);
void		ft_create_philo(t_data *data);

#endif