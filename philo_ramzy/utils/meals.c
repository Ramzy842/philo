/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 19:24:42 by rchahban          #+#    #+#             */
/*   Updated: 2023/06/25 22:52:30 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void last_meal_time(t_single_philo *philo, long start_time)
{
	// pthread_mutex_lock(&philo->philos->races);
	// pthread_mutex_lock(philo->test);
	// if (philo->philos->death_occured == 0)
	// {
		// pthread_mutex_unlock(&philo->philos->races);
		//pthread_mutex_lock(&philo->philos->races);
		philo->last_meal = get_timestamp_ms() - start_time;
		//pthread_mutex_unlock(&philo->philos->races);
		// printf ("ana thread nmra %d last meal dyali daz 3liha %d\n", philo->num + 1, philo->last_meal);
	// }
	// pthread_mutex_unlock(&philo->philos->races);
	// pthread_mutex_unlock(philo->test);
}

int handle_meals_count(t_single_philo *philo)
{
	// pthread_mutex_lock(&philo->philos->races);
	// pthread_mutex_lock(philo->test);
	// if (philo->philos->death_occured == 0)
	// {
		//pthread_mutex_lock(&philo->philos->races);
		
		philo->philos->n_of_times_each_philo_must_eat--;
		// printf ("num of meals = %d\n" ,philo->philos->n_of_times_each_philo_must_eat);
		return (philo->philos->n_of_times_each_philo_must_eat);
		
		// philo->philos->death_occured = 1;
		//pthread_mutex_unlock(&philo->philos->races);
	// }
	// pthread_mutex_unlock(&philo->philos->races);
	// pthread_mutex_unlock(philo->test);
}
