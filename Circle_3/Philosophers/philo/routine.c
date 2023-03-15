/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:41:51 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/16 00:28:48 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	pickup(t_philo *philo)
{
	const int				n = philo->attr->num_of_philosophers;
	t_shared_data *const	data = philo->data;

	pthread_mutex_lock(&(data->fork_mutex[philo->id]));
	print_state(&(data->print_mutex), data->start_time, philo->id, FORK);
	pthread_mutex_lock(&(data->fork_mutex[(philo->id + 1) % n]));
	print_state(&(data->print_mutex), data->start_time, philo->id, FORK);
}

void	eat(t_philo *philo)
{
	t_shared_data *const	data = philo->data;

	pthread_mutex_lock(&(philo->mutex));
	philo->last_eat_time = get_milisecond(0);
	philo->eat_count++;
	pthread_mutex_unlock((&philo->mutex));
	print_state(&(data->print_mutex), data->start_time, philo->id, EAT);
	msleep(philo->attr->time_to_eat);
}

void	putdown(t_philo *philo)
{
	const int				n = philo->attr->num_of_philosophers;
	t_shared_data *const	data = philo->data;

	pthread_mutex_unlock(&(data->fork_mutex[(philo->id + 1) % n]));
	pthread_mutex_unlock(&(data->fork_mutex[philo->id]));
}

void	*routine(void *philosopher)
{
	t_philo *const			philo = philosopher;
	t_shared_data *const	data = philo->data;

	if (philo->id % 2)
		msleep(100);
	while (1)
	{
		if (check_end(data))
			break ;
		pickup(philo);
		eat(philo);
		putdown(philo);
		if (check_end(data))
			break ;
		print_state(&(data->print_mutex), data->start_time, philo->id, SLEEP);
		msleep(philo->attr->time_to_sleep);
		print_state(&(data->print_mutex), data->start_time, philo->id, THINK);
	}
	return (NULL);
}
