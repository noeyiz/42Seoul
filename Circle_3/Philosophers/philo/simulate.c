/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 22:38:53 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/16 01:24:28 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_philo philo)
{
	long long	time;
	
	pthread_mutex_lock(&philo.mutex);
	time = get_milisecond(philo.last_eat_time);
	pthread_mutex_unlock(&philo.mutex);
	if (time >= philo.attr->time_to_die)
		return (1);
	return (0);
}

int	check_done(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo[0].attr->num_of_philosophers)
	{
		pthread_mutex_lock(&philo[i].mutex);
		if (philo[i].eat_count < philo[0].attr->num_of_times_to_must_eat)
		{
			pthread_mutex_unlock(&philo[i].mutex);
			return (0);
		}
		pthread_mutex_unlock(&philo[i].mutex);
	}
	return (1);
}

void	monitoring(t_philo *philos)
{
	t_common_attr *const	attr = philos[0].attr;
	t_shared_data *const	data = philos[0].data;
	int						i;
	int						end;
	
	end = 0;
	while (1)
	{
		i = -1;
		while (end == 0 && ++i < attr->num_of_philosophers)
			end = check_die(philos[i]);
		if (end)
		{
			printf(RED"die\n"RESET);
			print_state(&(data->print_mutex), data->start_time, i + 1, DIE);
			break ;
		}
		if (attr->num_of_times_to_must_eat && check_done(philos))
		{
			printf(YELLOW"done\n"RESET);
			break ;
		}
	}	
}

void	simulate(t_philo *philos)
{
	const int	n = philos[0].attr->num_of_philosophers;
	int			i;

	i = -1;
	while (++i < n)	
	{
		pthread_create(&philos[i].thread, NULL, routine, &philos[i]);
		pthread_detach(philos[i].thread);
	}
	monitoring(philos);
}
