/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:04:45 by rchahban          #+#    #+#             */
/*   Updated: 2023/06/25 17:45:26 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void eat(t_single_philo *philo, long start_time)
{
		// pthread_mutex_lock(&philo->philos->races);
		printf("%lu %d is eating\n",
		get_timestamp_ms() - start_time, philo->num + 1);
		// pthread_mutex_unlock(&philo->philos->races);
}

void take_forks(t_single_philo *philo, long start_time)
{
	pthread_mutex_lock(philo->fork_left);
	printf("%lu %d has taken a fork\n",
		get_timestamp_ms() - start_time, philo->num + 1);
	pthread_mutex_lock(philo->fork_right);
	printf("%lu %d has taken a fork\n",
		get_timestamp_ms() - start_time, philo->num + 1);
}

void drop_forks(t_single_philo *philo)
{
	// pthread_mutex_lock(&philo->philos->races);
	// pthread_mutex_lock(philo->test);
	// if (philo->philos->death_occured == 0)
	// {
		// pthread_mutex_unlock(philo->test);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
	// }
	// pthread_mutex_unlock(&philo->philos->races);
	// pthread_mutex_unlock(philo->test);
}

void think(t_single_philo *philo, long start_time)
{
	// pthread_mutex_lock(&philo->philos->races);
	pthread_mutex_lock(&philo->philos->races);
	// if (philo->philos->death_occured == 0)
	// {
		// pthread_mutex_unlock(philo->test);
		printf("%lu %d is thinking\n",
			   get_timestamp_ms() - start_time, philo->num + 1);
	// }
	// pthread_mutex_unlock(&philo->philos->races);
	pthread_mutex_unlock(&philo->philos->races);
}

void sleep_philo(t_single_philo *philo, long start_time)
{
	// pthread_mutex_lock(&philo->philos->races);
	// pthread_mutex_lock(&philo->philos->races);
	// if (philo->philos->death_occured == 0)
	// {
		// pthread_mutex_unlock(philo->test);
		printf("%lu %d is sleeping\n",
			   get_timestamp_ms() - start_time, philo->num + 1);
	// }
	// pthread_mutex_unlock(&philo->philos->races);
	// pthread_mutex_unlock(&philo->philos->races);
}
