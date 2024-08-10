/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mutex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:18:55 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 06:19:08 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_action(long time, t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->table->mutex);
	if (philo->table->status == ALIVE)
	{
		printf("%ld\t%d %s\n", time, philo->id, action);
		pthread_mutex_unlock(&philo->table->mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->table->mutex);
		usleep(50);
	}
}
