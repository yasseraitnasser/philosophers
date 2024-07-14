/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 21:07:48 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/14 01:22:49 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	algo_implementation(t_philo *philo)
{
	printf("%ld\n", philo->input->nbr_of_philos);
	printf("%ld\n", philo->input->time_to_die);
	printf("%ld\n", philo->input->time_to_eat);
	printf("%ld\n", philo->input->time_to_sleep);
	printf("%ld\n", philo->input->times_each_philo_must_eat);
	free(philo->input);
	free(philo);
}
