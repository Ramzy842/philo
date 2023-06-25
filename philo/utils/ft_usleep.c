/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchahban <rchahban@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 17:04:55 by rchahban          #+#    #+#             */
/*   Updated: 2023/06/24 17:08:01 by rchahban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	get_timestamp_ms(void)
{
	struct timeval	time;
	size_t			tm;

	gettimeofday(&time, NULL);
	tm = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (tm);
}

void	ft_usleep(long time, int sleeping)
{
	while (1)
	{
		if (get_timestamp_ms() >= time + sleeping)
			break ;
		usleep(100);
	}
}
