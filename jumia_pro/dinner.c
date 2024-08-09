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
		ft_usleep(50); // to change
	}
}

void	*one_philo_routine(void *data;)
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
	ultimate_usleep(philo->table->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_philo_action(gettime(philo->table->simulation_start, philo, "is sleeping"));
	ultimate_usleep(philo->table->time_to_sleep, philo);
	print_philo_action(gettime(table->simulation_start, philo, "is thinking"));
}

void	first_meal(t_philo *philo)
{
	if (philo->table->nbr_of_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			philo_cycle(philo);
	}
	else
	{
		if (philo->id % 2 == 0
				&& philo->id != philo->table->nbr_of_philos - 1)
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
	ft_usleep(500) // to change as well
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
		pthread_create(&tmp->thread, NULL, routine, philo);
		philo = philo->next;
		i++;
	}
}

void	dinner_time(t_table *table)
{
	int	i;
	t_philo	*tmp;

	i = 0;
	tmp = table->philos;
	if (table->nbr_of_philos == 1)
	{
		pthread_create(&table->thread, NULL,
			one_philo_routine, table->philos);
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
	ft_clean(table);
}
