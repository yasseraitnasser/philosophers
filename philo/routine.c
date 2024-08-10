/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:18:21 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 06:18:46 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*one_philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	print_philo_action(gettime(philo->table->simulation_start),
		philo, "has taken a fork");
	return (NULL);
}

void	philo_cycle(t_philo *philo, long start)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo_action(gettime(start), philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_philo_action(gettime(start), philo, "has taken a fork");
	print_philo_action(gettime(start), philo, "is eating");
	pthread_mutex_lock(&philo->table->mutex);
	if (philo->table->status == DEAD)
	{
		pthread_mutex_unlock(&philo->table->mutex);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	philo->last_meal_time = gettime(0);
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->table->mutex);
	ft_usleep_mutex(philo->table->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_philo_action(gettime(start), philo, "is sleeping");
	ft_usleep_mutex(philo->table->time_to_sleep, philo);
	print_philo_action(gettime(start), philo, "is thinking");
}

void	first_meal(t_philo *philo)
{
	if (philo->table->nbr_of_philos % 2 == 0)
	{
		if (philo->id % 2)
			philo_cycle(philo, philo->table->simulation_start);
	}
	else
	{
		if (philo->id % 2 && philo->id != philo->table->nbr_of_philos - 1)
			philo_cycle(philo, philo->table->simulation_start);
	}
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	print_philo_action(gettime(philo->table->simulation_start),
		philo, "is thinking");
	first_meal(philo);
	usleep(500);
	pthread_mutex_lock(&philo->table->mutex);
	while (philo->table->status == ALIVE)
	{
		pthread_mutex_unlock(&philo->table->mutex);
		philo_cycle(philo, philo->table->simulation_start);
		usleep(500);
		pthread_mutex_lock(&philo->table->mutex);
	}
	pthread_mutex_unlock(&philo->table->mutex);
	ft_usleep(500);
	return (NULL);
}
