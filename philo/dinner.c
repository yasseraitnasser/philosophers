/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:06:47 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 06:21:49 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring(t_philo *philo, long start)
{
	t_philo	*tmp;

	tmp = philo;
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (gettime(tmp->last_meal_time) > tmp->table->time_to_die)
		{
			pthread_mutex_unlock(&philo->mutex);
			break ;
		}
		if (check_if_full(philo) && philo->table->nbr_of_meals != -1)
		{
			printf("philo is full\n");
			philo->status = DEAD;
			pthread_mutex_unlock(&philo->mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->mutex);
		tmp = tmp->next;
	}
	pthread_mutex_lock(&philo->mutex);
	philo->status = DEAD;
	pthread_mutex_unlock(&philo->mutex);
	printf("%ld\t%d %s\n", gettime(0) - start, philo->id, "died");
}

void	dinner_time(t_table *table)
{
	int		i;
	t_philo	*tmp;

	i = 0;
	tmp = table->philos;
	if (table->nbr_of_philos == 1)
	{
		pthread_create(&tmp->thread, NULL,
			one_philo_routine, tmp);
	}
	else
		create_threads(tmp);
	monitoring(tmp, table->simulation_start);
	while (i < table->nbr_of_philos)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
		i++;
	}
}
