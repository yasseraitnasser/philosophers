/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 17:18:59 by yait-nas          #+#    #+#             */
/*   Updated: 2024/08/10 06:15:52 by yait-nas         ###   ########.fr       */
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

# define ALIVE 0
# define DEAD 1

typedef struct s_table	t_table;

typedef struct s_philo
{
	int						id;
	int						meals_counter;
	long					last_meal_time;
	pthread_t				thread;
	pthread_mutex_t			*right_fork;
	pthread_mutex_t			*left_fork;
	t_table					*table;
	struct s_philo			*next;
}	t_philo;

typedef struct s_table
{
	long					nbr_of_philos;
	long					time_to_die;
	long					time_to_eat;
	long					time_to_sleep;
	long					nbr_of_meals;
	long					simulation_start;
	int						status;
	pthread_mutex_t			mutex;
	pthread_mutex_t			*forks;
	t_philo					*philos;
}	t_table;

int		parsing(char **argv, t_table *table);
int		last_check(t_table *table);
int		check_each_argument(char *str);
long	ft_atol(const char *str);
void	data_init(t_table *table);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo	*ft_lstnew(int id, pthread_mutex_t *forks, t_table *table);
void	dinner_time(t_table *table);
long	gettime(long time);
void	*routine(void *data);
void	print_action(long time, t_philo *philo, char *str);
void	ft_usleep_mutex(long time, t_philo *philo);
void	ft_usleep(long time);
void	clean_up(t_table *table);
void	monitoring(t_philo *philo, long start);
int		check_if_full(t_philo *philo);
void	create_threads(t_philo *philo);
void	*routine(void *data);
void	first_meal(t_philo *philo);
void	philo_cycle(t_philo *philo, long start);
void	*one_philo_routine(void *data);
void	print_philo_action(long time, t_philo *philo, char *action);

#endif
