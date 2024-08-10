/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:19:29 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 06:19:49 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->nbr_of_philos)
	{
		pthread_create(&philo->thread, NULL, routine, philo);
		philo = philo->next;
		i++;
	}
}

int	check_if_full(t_philo *philo)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = philo->table->nbr_of_philos;
	while (philo->meals_counter >= philo->table->nbr_of_meals && i <= tmp)
	{
		i++;
		philo = philo->next;
	}
	if (i >= philo->table->nbr_of_philos)
		return (1);
	return (0);
}
