/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:23 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/05 21:30:42 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo
{
	long	nbr_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	times_each_philo_must_eat;
}	t_philo_infos;

int		parsing(char **argv);
int		check_each_argument(char *str);
void	init(t_philo_infos *infos, char **argv);
long	ft_atoi(const char *str);
void	philo(t_philo_infos *infos);
int		last_check(t_philo_infos *infos);

#endif
