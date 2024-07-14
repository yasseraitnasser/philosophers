/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:23 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/14 01:05:49 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_input
{
	long	nbr_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	times_each_philo_must_eat;
}	t_input;

typedef struct s_philo
{
	int				id;
	t_input			*input;
	struct s_philo	*next;
}	t_philo;

int		parsing(char **argv);
int		check_each_argument(char *str);
void	init(t_philo *philo, char **argv);
long	ft_atoi(const char *str);
void	algo_implementation(t_philo *philo);
int		last_check(t_input *infos);

#endif
