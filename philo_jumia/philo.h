/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:18:59 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/06 17:33:40 by yait-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_table t_table;

typedef struct s_philo
{
	int	id;
	int	meals_counter;
	long	last_meal;
	pthread_t	thread;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	t_table	*table;
	struct s_philo	*next;
}	t_philo;

typedef struct s_table
{
	long	nbr_of_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	nbr_of_meals;
	long	simulation_start;
	pthread_mutex_t	write_mutex;
	t_philo	*philos;
}	t_table;

int	parsing(char **argv, t_table *table);
int	last_check(t_table *table);
int	check_each_argument(char *str);
long	ft_atol(const char *str);
void	data_init(t_table *table);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo	*ft_lstnew(int	id, pthread_mutex_t *forks, t_table *table);
void	dinner_time(t_table *table);
long	gettime(void);

#endif