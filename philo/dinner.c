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
		pthread_mutex_lock(&philo->table->mutex);
		if (gettime(tmp->last_meal_time) > tmp->table->time_to_die)
		{
			pthread_mutex_unlock(&philo->table->mutex);
			break ;
		}
		if (check_if_full(philo) && philo->table->nbr_of_meals != -1)
		{
			philo->table->status = FULL;
			pthread_mutex_unlock(&philo->table->mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->table->mutex);
		tmp = tmp->next;
	}
	print_philo_action(gettime(0) - start, philo, "died");
	pthread_mutex_lock(&philo->table->mutex);
	philo->table->status = DEAD;
	pthread_mutex_unlock(&philo->table->mutex);
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
