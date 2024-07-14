/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-nas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:59:23 by yait-nas          #+#    #+#             */
/*   Updated: 2024/07/14 21:38:42 by yait-nas         ###   ########.fr       */
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
	long	nbr_of_meals;
}	t_input;

typedef struct s_philo
{
	int				id;
	t_input			*input;
	struct s_philo	*next;
}	t_philo;

int		parsing(char **argv);
int		check_each_argument(char *str);
void	init1(t_input *input, char **argv);
void	init2(t_philo **philo, t_input *input);
long	ft_atoi(const char *str);
void	algo_implementation(t_philo *philo);
int		last_check(t_input *infos);
t_philo	*ft_lstnew(t_input *input, int i);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
int	ft_lstsize(t_philo *lst);
t_philo	*ft_lstlast(t_philo *lst);

#endif
