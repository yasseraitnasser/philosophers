/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:07:48 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/05 21:30:08 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo(t_philo_infos *infos)
{
	printf("%ld\n", infos->nbr_of_philos);
	printf("%ld\n", infos->time_to_die);
	printf("%ld\n", infos->time_to_eat);
	printf("%ld\n", infos->time_to_sleep);
	printf("%ld\n", infos->times_each_philo_must_eat);
}
