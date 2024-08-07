/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 16:50:47 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/06 21:43:46 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_table *table)
{
	pthread_mutex_t	*forks;
	int		i;
	t_philo		*head;
	t_philo		*tmp;

	head = NULL;
	forks = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philos);
	if (!forks)
		return ;
	i = 0;
	while (i < table->nbr_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		tmp = ft_lstnew(i, forks, table);
		ft_lstadd_back(&head, tmp);
		i++;
	}
	tmp->next = head;
	table->philos = head;
	table->simulation_start = gettime();
}
