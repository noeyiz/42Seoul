/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:35:05 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/16 20:42:12 by jikoo            ###   ########.fr       */
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

void	monitoring(t_philo_data *data)
{
	int	i;
	int	is_anyone_dead;

	is_anyone_dead = 0;
	while (1)
	{
		i = -1;
		while (!is_anyone_dead && ++i < data->num_of_philosophers)
			is_anyone_dead = check_die(data, i);
		if (is_anyone_dead)
		{
			printf(RED"someone die ....... 😈\n"RESET);
			print_state(&data->print_mutex, data->start_time, i, DIE);
			break ;
		}
		if (data->num_of_times_to_must_eat && check_done(data))
		{
			printf(YELLOW"every philosophers is full ~~~ 😁\n"RESET);
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
	{
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		pthread_detach(philos[i].thread);
	}
	monitoring(philos[0].data);
}
