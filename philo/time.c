/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:30:37 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/09 22:14:41 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(long time)
{
	struct timeval	tv;
	long			tmp;

	gettimeofday(&tv, NULL);
	tmp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (tmp - time);
}

void	ft_usleep_mutex(long time, t_philo *philo)
{
	struct timeval	tv;
	long			tmp;

	gettimeofday(&tv, NULL);
	tmp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (tv.tv_sec * 1000 + tv.tv_usec / 1000 - tmp < time)
	{
		pthread_mutex_lock(&philo->table->mutex);
		if (philo->table->status == DEAD)
		{
			pthread_mutex_unlock(&philo->table->mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->table->mutex);
		usleep(1);
		gettimeofday(&tv, NULL);
	}
}

void	ft_usleep(long time)
{
	struct timeval	tv;
	long			tmp;

	gettimeofday(&tv, NULL);
	tmp = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	while (tv.tv_sec * 1000 + tv.tv_usec / 1000 - tmp < time)
	{
		usleep(1);
		gettimeofday(&tv, NULL);
	}
}
