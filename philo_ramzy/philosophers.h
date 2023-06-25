/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:07:32 by rchahban          #+#    #+#             */
/*   Updated: 2023/06/25 22:37:41 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos	t_philos;
typedef struct s_single_philo
{
	pthread_t		th;
	int				num;
	// pthread_mutex_t	*test;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	// int				number_of_meals;
	int				last_meal;
	t_philos		*philos;
}	t_single_philo;

typedef struct s_philos
{
	int				end_of_eat;
	int				av5_present;
	int				number_of_philosophers;
	pthread_mutex_t	*forks;
	// pthread_mutex_t	death;
	pthread_mutex_t	races;
	// pthread_mutex_t	last_meal;
	// pthread_mutex_t	n_of_meals;
	long			start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_of_times_each_philo_must_eat;
	int				death_occured;
	t_single_philo	*philo;
}	t_philos;

int		ft_atoi(const char *str);
void	ft_usleep(long time, int sleeping);
long	get_timestamp_ms(void);
int		create_mutex(t_philos *philos);
int		death_philo(t_philos *philos);

// actions
void	eat(t_single_philo *philo, long start_time);
void	take_forks(t_single_philo *philo, long start_time);
void	drop_forks(t_single_philo *philo);
void	think(t_single_philo *philo, long start_time);
void	sleep_philo(t_single_philo *philo, long start_time);

// meals
void	last_meal_time(t_single_philo *philo, long start_time);
int		handle_meals_count(t_single_philo *philo);
#endif