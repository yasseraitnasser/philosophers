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

void	dinner_time(t_table *table)
{
	int	i;
	printf("%ld\n", table->nbr_of_philos);
	printf("%ld\n", table->time_to_die);
	printf("%ld\n", table->time_to_eat);
	printf("%ld\n", table->time_to_sleep);
	printf("%ld\n", table->nbr_of_meals);
	t_philo	*tmp;
	tmp = table->philos;
	i = 0;
	while (i < table->nbr_of_philos)
	{
		printf("id %d | right fork %p | left fork %p\n", tmp->id, tmp->right_fork, tmp->left_fork);
		tmp = tmp->next;
		i++;
	}
	// check if the init went good // to do
}
