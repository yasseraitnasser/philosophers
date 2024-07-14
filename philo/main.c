/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:42:43 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/14 21:45:37 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init1(t_input *input, char **argv)
{
	input->nbr_of_philos = ft_atoi(argv[1]);
	input->time_to_die = ft_atoi(argv[2]);
	input->time_to_eat = ft_atoi(argv[3]);
	input->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		input->nbr_of_meals = ft_atoi(argv[5]);
	else
		input->nbr_of_meals = -1;
}

void	init2(t_philo **philo, t_input *input)
{
	t_philo	*tmp;
	int		i;

	*philo = NULL;
	i = 0;
	while (i < input->nbr_of_philos)
	{
		tmp = ft_lstnew(input, i);
		if (!tmp)
			return ; // work to do befor return
		ft_lstadd_back(philo, tmp);
		if (!philo)
			return ; // same thing here
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_philo	*philo;
	t_input	*input;

	if (argc == 5 || argc == 6)
	{
		if (!parsing(argv))
		{
			input = malloc(sizeof(t_input));
			if (!input)
				return (1);
			init1(input, argv);
			init2(&philo, input);
			while (philo)
			{
				printf("%d\n", philo->id);
				printf("%ld\n", philo->input->nbr_of_philos);
				printf("%ld\n", philo->input->time_to_die);
				printf("%ld\n", philo->input->time_to_eat);
				printf("%ld\n", philo->input->time_to_sleep);
				printf("%ld\n", philo->input->nbr_of_meals);
				printf("-------------------------------------");
				philo = philo-> next;
			}
			exit(0);
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
