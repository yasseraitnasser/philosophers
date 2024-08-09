/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 17:24:31 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/06 21:46:18 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_action(long time, t_philo *philo, char *str)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex, NULL);
	pthread_mutex_lock(&mutex);
	if (!philo->status)
	{
		printf("%ld\t%d %s\n", time, philo->id, str);
		pthread_mutex_unlock(&mutex);
	}
	else
	{
		pthread_mutex_unlock(&mutex);
		usleep(50);
	}
}

void	philo_cycle(t_philo *philo, long start_time)
{
	pthread_mutex_t	mutex;

	pthread_mutex_init(&mutex);
	pthread_mutex_lock(philo->right_fork);
	print_action(gettime(start_time), philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_action(gettime(start_time), philo, "has taken a fork");
	print_action(gettime(start_time), philo, "is eating");
	pthread_mutex_lock(&mutex);
	if (philo->status)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(&mutex);
		return ;
	}
	philo->last_meal = gettime(0);
	philo->meals_counter++;
	pthread_mutex_unlock(philo->left_fork);
	ft_usleep(); // TO DO
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_action(gettime(start_time), philo, "is sleeping")
	ft_usleep(); // TO DO
	print_action(gettime(start_time), philo, "is thinking");
}

void	first_meal(t_philo *philo, long start_time)
{
	if (philo->nbr_of_philos % 2)
		if (!philo->id % 2)
			philo_cycle(philo, start_time);
	else
		if (!philo->id % 2)
			philo_cycle(philo, start_time);
}

void	*routine(void *data)
{
	t_philo	*philo;
	long	start_time;

	philo = (t_philo *)data;
	start_time = philo->table->simulation_start;
	print_action(gettime(start_time), philo, "is thinking"); // to do
	first_meal(philo, start_time);
	return (NULL);
}

void	dinner_time(t_table *table)
{
	t_philo	*tmp;
	int		i;
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * table->nbr_of_philos);
	if (!threads)
		return ;
	i = 0;
	tmp = table->philos;
	while (i < table->nbr_of_philos)
	{
		if (pthread_create(threads + i, NULL, routine, tmp))
		{
			printf("pthread_create failed\n");
			return ;
		}
		tmp = tmp->next;
		i++;
	}
	//ft_monitoring(table->philo); // to do :)
	i = 0;
	while (i < table->nbr_of_philos)
		pthread_join(threads[i++], NULL);
}
