/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:42:43 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/05 21:30:57 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo_infos *infos, char **argv)
{
	infos->nbr_of_philos = ft_atoi(argv[1]);
	infos->time_to_die = ft_atoi(argv[2]);
	infos->time_to_eat = ft_atoi(argv[3]);
	infos->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		infos->times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		infos->times_each_philo_must_eat = -1;
}

int	main(int argc, char **argv)
{
	t_philo_infos	*infos;

	if (argc == 5 || argc == 6)
	{
		if (!parsing(argv))
		{
			infos = malloc(sizeof(t_philo_infos));
			init(infos, argv);
			if (last_check(infos))
				philo(infos);
			else
				write(1, "invalid\n", 8);
		}
		else
			write(1, "invalid\n", 8);
	}
}
