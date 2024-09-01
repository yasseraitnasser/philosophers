/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 06:20:08 by yait-nas          #+#    #+#             */
/*   Updated: 2024/09/02 00:19:37 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_up(t_table *table)
{
	int		i;
	t_philo	*tmp1;
	t_philo	*tmp2;

	i = 0;
	tmp1 = table->philos;
	while (i < table->nbr_of_philos)
	{
		tmp2 = tmp1->next;
		pthread_mutex_destroy(tmp1->right_fork);
		pthread_mutex_destroy(tmp1->left_fork);
		free(tmp1);
		tmp1 = tmp2;
		i++;
	}
	pthread_mutex_destroy(&table->mutex);
	free(table->forks);
}
