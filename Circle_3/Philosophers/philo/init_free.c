/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:39:38 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/16 21:02:40 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "philo.h"

static int	ph_atoi(char *str)
{
	long long	num;
	int			sign;

	num = 0;
	sign = 1;
	while (*str == '\t' || *str == '\n' || *str == '\v'
		|| *str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		if (num > 2147483647 || sign * num < -2147483648)
			return (-1);
		str++;
	}
	if (*str)
		return (-1);
	return (sign * num);
}

static int	init_arr_philo_data(t_philo_data *data, int n)
{
	int	i;

	data->eat_count = malloc(sizeof(int) * n);
	data->last_eat_time = malloc(sizeof(long long) * n);
	data->eat_mutex = malloc(sizeof(pthread_mutex_t) * n);
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * n);
	if (!data->eat_count || !data->last_eat_time
		|| !data->eat_mutex || !data->fork_mutex)
		return (0);
	i = -1;
	while (++i < n)
	{
		data->eat_count[i] = 0;
		data->last_eat_time[i] = data->start_time;
		pthread_mutex_init(&data->eat_mutex[i], NULL);
		pthread_mutex_init(&data->fork_mutex[i], NULL);
	}
	return (1);
}

int	init_philo_data(t_philo_data *data, char **argv)
{
	data->num_of_philosophers = ph_atoi(argv[1]);
	data->time_to_die = ph_atoi(argv[2]);
	data->time_to_eat = ph_atoi(argv[3]);
	data->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		data->num_of_times_to_must_eat = ph_atoi(argv[5]);
	else
		data->num_of_times_to_must_eat = 0;
	if (data->num_of_philosophers <= 0 || data->time_to_die <= 0
		|| data->time_to_eat <= 0 || data->time_to_sleep <= 0
		|| data->num_of_times_to_must_eat < 0)
		return (0);
	return (1);
	data->start_time = get_milisecond(0);
	pthread_mutex_init(&data->print_mutex, NULL);
	if (init_arr_philo_data(data, data->num_of_philosophers) == 0)
		return (0);
	return (1);
}

int	init_philos(t_philo **philos, t_philo_data *data)
{
	int	n;
	int	i;

	n = data->num_of_philosophers;
	*philos = malloc(sizeof(t_philo) * n);
	if (!philos)
		return (0);
	i = -1;
	while (++i < n)
	{
		(*philos)[i].id = i;
		(*philos)[i].left = i;
		(*philos)[i].right = (i + 1) % n;
		(*philos)[i].data = data;
	}
	return (0);
}

void	free_all(t_philo **philos)
{
	t_philo_data	*data;
	int				i;

	if (*philos)
	{
		data = (*philos)[0].data;
		i = -1;
		while (++i < data->num_of_philosophers)
		{
			pthread_mutex_destroy(&data->eat_mutex[i]);
			pthread_mutex_destroy(&data->fork_mutex[i]);
		}
		pthread_mutex_destroy(&data->print_mutex);
		free(data->eat_count);
		free(data->last_eat_time);
		free(data->eat_mutex);
		free(data->fork_mutex);
		free(*philos);
	}
}
