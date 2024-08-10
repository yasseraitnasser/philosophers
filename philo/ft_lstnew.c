/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:04:44 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 04:56:51 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int id, pthread_mutex_t *forks, t_table *table)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new -> last_meal_time = table->simulation_start;
	new -> id = id + 1;
	new -> meals_counter = 0;
	new -> right_fork = &forks[new->id - 1];
	new -> left_fork = &forks[new->id % table->nbr_of_philos];
	new -> table = table;
	new -> next = NULL;
	return (new);
}
