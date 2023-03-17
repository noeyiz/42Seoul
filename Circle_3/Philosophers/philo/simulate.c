/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:35:05 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/17 20:56:44 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_die(t_philo_data *data, int idx)
{
	long long	time;

	pthread_mutex_lock(&data->eat_mutex[idx]);
	time = get_milisecond(data->last_eat_time[idx]);
	pthread_mutex_unlock(&data->eat_mutex[idx]);
	if (time >= data->time_to_die)
		return (1);
	return (0);
}

static int	check_done(t_philo_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philosophers)
	{
		pthread_mutex_lock(&data->eat_mutex[i]);
		if (data->eat_count[i] < data->num_of_times_to_must_eat)
		{
			pthread_mutex_unlock(&data->eat_mutex[i]);
			return (0);
		}
		pthread_mutex_unlock(&data->eat_mutex[i]);
	}
	return (1);
}

void	set_end(t_philo_data *data)
{
	pthread_mutex_lock(&data->end_mutex);
	data->end_flag = 1;
	pthread_mutex_unlock(&data->end_mutex);
}

void	monitoring(t_philo_data *data)
{
	int	idx;
	int	end;

	end = 0;
	while (1)
	{
		idx = -1;
		while (end == 0 && ++idx < data->num_of_philosophers)
			end = check_die(data, idx);
		if (end)
		{
			set_end(data);
			print_die(&data->print_mutex, data->start_time, idx);
			break ;
		}
		if (data->num_of_times_to_must_eat && check_done(data))
		{
			set_end(data);
			print_done(&data->print_mutex);
			break ;
		}
	}
}

void	simulate(t_philo *philos)
{
	int	n;
	int	i;

	n = philos[0].data->num_of_philosophers;
	i = -1;
	while (++i < n)
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
	monitoring(philos[0].data);
	while (--i)
		pthread_join(philos[i].thread, NULL);
}
