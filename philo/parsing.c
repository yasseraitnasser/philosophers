/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:32:15 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/04 18:12:14 by yait-nas         ###   ########.fr       */
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

int	last_check(t_table *table)
{
	if (table->nbr_of_philos > INT_MAX
		|| table->time_to_die > INT_MAX
		|| table->time_to_eat > INT_MAX
		|| table->time_to_sleep > INT_MAX
		|| table->nbr_of_meals > INT_MAX)
		return (1);
	return (0);
}

int	parsing(char **argv, t_table *table)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_each_argument(argv[i]))
			return (1);
		i++;
	}
	table->nbr_of_philos = ft_atol(argv[1]);
	table->time_to_die = ft_atol(argv[2]);
	table->time_to_eat = ft_atol(argv[3]);
	table->time_to_sleep = ft_atol(argv[4]);
	if (argv[5])
		table->nbr_of_meals = ft_atol(argv[5]);
	else
		table->nbr_of_meals = -1;
	if (last_check(table))
		return (1);
	return (0);
}
