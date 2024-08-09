/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:04:44 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 00:21:28 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_lstnew(int	id, pthread_mutex_t *forks, t_table *table)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	pthread_mutex_init(&new->mutex, NULL);
	new -> id = id + 1;
	new -> meals_counter = 0;
	new -> right_fork = &forks[new->id - 1];
	new -> left_fork = &forks[new->id % table->nbr_of_philos];
	new -> status = ALIVE;
	new -> table = table;
	new -> next = NULL;
	return (new);
}
