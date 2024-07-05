/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:01:53 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/05 21:32:25 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_each_argument(char *str)
{
	int	i;
	int	digits;

	i = 0;
	digits = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (1);
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		return (1);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		i++;
		digits++;
	}
	if (str[i] || digits > 10)
		return (1);
	return (0);
}

int	parsing(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_each_argument(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

int	last_check(t_philo_infos *infos)
{
	if (infos->nbr_of_philos > INT_MAX
		|| infos->time_to_die > INT_MAX
		|| infos->time_to_eat > INT_MAX
		|| infos->time_to_sleep > INT_MAX
		|| infos->times_each_philo_must_eat > INT_MAX)
		return (0);
	return (1);
}
