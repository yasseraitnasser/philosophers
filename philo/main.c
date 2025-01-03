/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:19:49 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 22:43:00 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc == 5 || argc == 6)
	{
		if (!parsing(argv, &table))
		{
			if (table.nbr_of_meals)
			{
				data_init(&table);
				dinner_time(&table);
				clean_up(&table);
			}
		}
		else
			printf("invalid input\n");
	}
	else
		printf("invalid number of arguments\n");
}
