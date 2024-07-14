/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:42:43 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/14 01:28:30 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init(t_philo *philo, char **argv)
{
	philo->input->nbr_of_philos = ft_atoi(argv[1]);
	philo->input->time_to_die = ft_atoi(argv[2]);
	philo->input->time_to_eat = ft_atoi(argv[3]);
	philo->input->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->input->times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		philo->input->times_each_philo_must_eat = -1;
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	if (argc == 5 || argc == 6)
	{
		if (!parsing(argv))
		{
			philo = malloc(sizeof(t_philo));
			philo->input = malloc(sizeof(t_input));
			if (!philo || !philo->input)
				return (1);
			init(philo, argv);
			if (last_check(philo->input))
				algo_implementation(philo);
			else
			{
				free(philo->input);
				free(philo);
				write(1, "invalid\n", 8);
			}
		}
		else
			write(1, "invalid\n", 8);
	}
}
