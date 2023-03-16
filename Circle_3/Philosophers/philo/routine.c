/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 20:18:15 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/16 20:41:47 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	pickup(t_philo *philo)
{
	t_philo_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->fork_mutex[philo->left]);
	print_state(&data->print_mutex, data->start_time, philo->id, FORK);
	pthread_mutex_lock(&data->fork_mutex[philo->right]);
	print_state(&data->print_mutex, data->start_time, philo->id, FORK);
}

static void	eat(t_philo *philo)
{
	t_philo_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->eat_mutex[philo->id]);
	data->last_eat_time[philo->id] = get_milisecond(0);
	data->eat_count[philo->id]++;
	pthread_mutex_unlock(&data->eat_mutex[philo->id]);
	print_state(&data->print_mutex, data->start_time, philo->id, EAT);
	msleep(data->time_to_eat);
}

static void	putdown(t_philo *philo)
{
	t_philo_data	*data;

	data = philo->data;
	pthread_mutex_unlock(&data->fork_mutex[philo->right]);
	pthread_mutex_unlock(&data->fork_mutex[philo->left]);
}

void	*routine(void *philosophers)
{
	t_philo			*philo;
	t_philo_data	*data;

	philo = (t_philo *)philosophers;
	data = philo->data;
	if (philo->id % 2)
		msleep(data->time_to_eat);
	while (1)
	{
		pickup(philo);
		eat(philo);
		putdown(philo);
		print_state(&data->print_mutex, data->start_time, philo->id, SLEEP);
		msleep(data->time_to_sleep);
		print_state(&data->print_mutex, data->start_time, philo->id, THINK);
	}
}
