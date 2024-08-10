/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:50:47 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 04:56:14 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_table *table)
{
	int			i;
	t_philo		*head;
	t_philo		*tmp;

	table->simulation_start = gettime(0);
	head = NULL;
	table->forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philos);
	if (!table->forks)
		return ;
	i = 0;
	while (i < table->nbr_of_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		tmp = ft_lstnew(i, table->forks, table);
		ft_lstadd_back(&head, tmp);
		i++;
	}
	tmp->next = head;
	table->philos = head;
}
