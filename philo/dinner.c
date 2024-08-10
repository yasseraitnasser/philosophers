#include "philo.h"

void	print_philo_action(long time, t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->mutex);
	if (philo->status == ALIVE)
	{
		printf("%ld\t%d %s\n", time, philo->id, action);
		pthread_mutex_unlock(&philo->mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->mutex);
		ft_usleep(50);
	}
}

void	*one_philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	print_philo_action(gettime(philo->table->simulation_start),
		philo, "has taken a fork");
	return (NULL);
}

void	philo_cycle(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	print_philo_action(gettime(philo->table->simulation_start), philo, "has taken a fork");
	pthread_mutex_lock(philo->left_fork);
	print_philo_action(gettime(philo->table->simulation_start), philo, "has taken a fork");
	print_philo_action(gettime(philo->table->simulation_start), philo, "is eating");
	pthread_mutex_lock(&philo->mutex);
	if (philo->status == DEAD)
	{
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return ;
	}
	philo->last_meal_time = gettime(0);
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->mutex);
	ft_usleep_mutex(philo->table->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_philo_action(gettime(philo->table->simulation_start), philo, "is sleeping");
	ft_usleep_mutex(philo->table->time_to_sleep, philo);
	print_philo_action(gettime(philo->table->simulation_start), philo, "is thinking");
}

void	first_meal(t_philo *philo)
{
	if (philo->table->nbr_of_philos % 2 == 0)
	{
		if (philo->id % 2)
			philo_cycle(philo);
	}
	else
	{
		if (philo->id % 2 && philo->id != philo->table->nbr_of_philos - 1)
			philo_cycle(philo);
	}
}

void	*routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	print_philo_action(gettime(philo->table->simulation_start),
		philo, "is thinking");
	first_meal(philo);
	ft_usleep(500);
	pthread_mutex_lock(&philo->mutex);
	while (philo->status == ALIVE)
	{
		pthread_mutex_unlock(&philo->mutex);
		philo_cycle(philo);
		usleep(500);
		pthread_mutex_lock(&philo->mutex);
	}
	pthread_mutex_unlock(&philo->mutex);
	ft_usleep(500);
	return (NULL);
}

void	create_threads(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->table->nbr_of_philos)
	{
		pthread_create(&philo->thread, NULL, routine, philo);
		philo = philo->next;
		i++;
	}
}

int	check_if_full(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->meals_counter >= philo->table->nbr_of_meals && i <= philo->table->nbr_of_philos)
	{
		i++;
		philo = philo->next;
	}
	if (i >= philo->table->nbr_of_philos)
		return (1);
	return (0);
}

void	monitoring(t_philo *philo)
{
	while (1)
	{
		pthread_mutex_lock(&philo->mutex);
		if (gettime(philo->last_meal_time) > philo->table->time_to_die)
		{
			pthread_mutex_unlock(&philo->mutex);
			break ;
		}
		if (check_if_full(philo) && philo->table->nbr_of_meals != -1)
		{
			philo->status = DEAD;
			pthread_mutex_unlock(&philo->mutex);
			return ;
		}
		pthread_mutex_unlock(&philo->mutex);
		philo = philo->next;
	}
	pthread_mutex_lock(&philo->mutex);
	philo->status = DEAD;
	pthread_mutex_unlock(&philo->mutex);
	printf("%ld\t%d %s\n", gettime(0) - philo->table->simulation_start, philo->id, "died");
}

void	clean_up(t_table *table)
{
	int	i;
	t_philo	*tmp1;
	t_philo	*tmp2;

	i = 0;
	tmp1 = table->philos;
	while (i < table->nbr_of_philos)
	{
		tmp2 = tmp1->next;
		pthread_mutex_destroy(tmp1->right_fork);
		pthread_mutex_destroy(tmp1->left_fork);
		pthread_mutex_destroy(&tmp1->mutex);
		free(tmp1);
		tmp1 = tmp2;
		i++;
	}
	free(table->forks);
}

void	dinner_time(t_table *table)
{
	int	i;
	t_philo	*tmp;

	i = 0;
	tmp = table->philos;
	if (table->nbr_of_philos == 1)
	{
		pthread_create(&tmp->thread, NULL,
			one_philo_routine, tmp);
	}
	else
		create_threads(tmp);
	monitoring(tmp);
	while (i < table->nbr_of_philos)
	{
		pthread_join(tmp->thread, NULL);
		tmp = tmp->next;
		i++;
	}
}
