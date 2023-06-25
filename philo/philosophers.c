/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:07:27 by rchahban          #+#    #+#             */
/*   Updated: 2023/06/25 15:51:08 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philosophers.h"

pthread_mutex_t g_test;

void *routine(void *arg)
{
	t_single_philo *philo;
	long start_time;

	philo = (t_single_philo *)arg;
	start_time = philo->philos->start_time;
	// pthread_mutex_lock(&philo->philos->races);
	pthread_mutex_lock(philo->test);
	while (!philo->philos->death_occured)
	{
		// pthread_mutex_unlock(&philo->philos->races);
		pthread_mutex_unlock(philo->test);
		think(philo, start_time);
		take_forks(philo, start_time);
		pthread_mutex_lock(philo->test);
		eat(philo, start_time);
		pthread_mutex_unlock(philo->test);
		ft_usleep(get_timestamp_ms(), philo->philos->time_to_eat);
		pthread_mutex_lock(philo->test);
		last_meal_time(philo, start_time);
		pthread_mutex_unlock(philo->test);
		handle_meals_count(philo);
		drop_forks(philo);
		sleep_philo(philo, start_time);
		ft_usleep(get_timestamp_ms(), philo->philos->time_to_sleep);
	}
	// pthread_mutex_unlock(&philo->philos->races);
	pthread_mutex_unlock(philo->test);
	return (NULL);
}

int check_number_of_meals(t_philos *philos)
{
	int x;
	int completed;

	x = 0;
	completed = 1;
	while (x < philos->number_of_philosophers)
	{
		if (philos->philo[x].number_of_meals != philos->n_of_times_each_philo_must_eat)
		{
			completed = 0;
			break;
		}
		x++;
	}
	if (completed == 0)
		return (0);
	return (completed);
}

int death_philo(t_philos *philos)
{
	int x;

	x = 0;
	while (x < philos->number_of_philosophers)
	{
		pthread_mutex_lock(philos->philo[x].test);
		if (((get_timestamp_ms() - philos->start_time) - philos->philo[x].last_meal >= philos->time_to_die))
		{
			pthread_mutex_unlock(philos->philo[x].test);
			philos->death_occured = 1;
			printf("%lu %d died\n",
				   get_timestamp_ms() - philos->start_time, philos->philo[x].num);
			return (1);
		}
		pthread_mutex_unlock(philos->philo[x].test);
		x++;
	}
	return (0);
}

int create_threads(t_philos *philos)
{
	int x;

	x = 0;
	philos->philo = malloc(sizeof(t_single_philo) * philos->number_of_philosophers);
	if (!philos->philo)
		return (0);
	while (x < philos->number_of_philosophers)
	{
		philos->philo[x].test = &g_test;
		philos->philo[x].philos = philos;
		philos->philo[x].num = x;
		philos->philo[x].last_meal = 0;
		philos->philo[x].fork_left = &philos->forks[x];
		philos->philo[x].fork_right = &philos->forks[(x + 1) % philos->number_of_philosophers];
		if (pthread_create(&philos->philo[x].th, NULL,
						   routine, &(philos->philo[x])) != 0)
			return (0);
		usleep(50);
		pthread_detach(philos->philo[x].th);
		x++;
	}
	return (1);
}

int create_mutex(t_philos *philos)
{
	int x;

	x = 0;
	pthread_mutex_init(&philos->races, NULL);
	pthread_mutex_init(&philos->death, NULL);
	//	pthread_mutex_init(&philos->last_meal, NULL);
	//	pthread_mutex_init(&philos->n_of_meals, NULL);
	philos->forks = malloc(sizeof(pthread_mutex_t) * philos->number_of_philosophers);
	while (x < philos->number_of_philosophers)
	{
		if (pthread_mutex_init(&philos->forks[x], NULL) != 0)
			return (0);
		x++;
	}
	return (1);
}

int initialize_props(t_philos *philos, char **argv)
{
	philos->number_of_philosophers = ft_atoi(argv[1]);
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		if (!(ft_atoi(argv[5]) <= 0))
		{
			philos->n_of_times_each_philo_must_eat = ft_atoi(argv[5]) * philos->number_of_philosophers;
		}
		else
			return (0);
	}
	return (1);
}

void end_thread_exec(t_philos *philos)
{
	int x;

	x = 0;
	while (x < philos->number_of_philosophers)
	{
		pthread_detach(philos->philo[x].th);
		x++;
	}
}

int main(int argc, char **argv)
{
	t_philos philos;
	pthread_mutex_init(&g_test, NULL);
	if (!(argc == 5 || argc == 6))
		return (1);
	if (ft_atoi(argv[1]) <= 0)
		return (1);
	if (!initialize_props(&philos, argv))
		return (1);
	philos.start_time = get_timestamp_ms();
	philos.death_occured = 0;
	create_mutex(&philos);
	create_threads(&philos);
	while (1)
	{
		if (death_philo(&philos))
			break;
		if (argv[5])
		{
			if (philos.n_of_times_each_philo_must_eat <= 0)
				break;
		}
	}
	int i = 0;
	while(i < philos.number_of_philosophers)
	{
		pthread_join(philos.philo[i].th, NULL);
		i++;
	}
	return (0);
}
