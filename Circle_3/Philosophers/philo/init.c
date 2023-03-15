/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:48:14 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/16 01:24:00 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	init_common_attr(t_common_attr *attr, char **argv)
{
	attr->num_of_philosophers = ph_atoi(argv[1]);
	attr->time_to_die = ph_atoi(argv[2]);
	attr->time_to_eat = ph_atoi(argv[3]);
	attr->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		attr->num_of_times_to_must_eat = ph_atoi(argv[5]);
	else
		attr->num_of_times_to_must_eat = 0;
	if (attr->num_of_philosophers <= 0 || attr->time_to_die <= 0
		|| attr->time_to_eat <= 0 || attr->time_to_sleep <= 0
		|| attr->num_of_times_to_must_eat < 0)
		return (0);
	return (1);
}

int	init_shared_data(t_shared_data *data, int n)
{
	int	i;

	data->start_time = get_milisecond(0);
	pthread_mutex_init(&data->print_mutex, NULL);
	data->fork_mutex = malloc(sizeof(pthread_mutex_t) * n);
	if (!data->fork_mutex)
		return (0);
	i = -1;
	while (++i < n)
		pthread_mutex_init(&data->fork_mutex[i], NULL);
	return (1);
}

int	init_philos(t_philo **philos, t_common_attr *attr, t_shared_data *data)
{
	const int	n = attr->num_of_philosophers;
	int			i;

	*philos = malloc(sizeof(t_philo) * n);
	if (!*philos)
		return (0);
	i = -1;
	while (++i < n)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].eat_count = 0;
		(*philos)[i].last_eat_time = data->start_time;
		pthread_mutex_init(&(*philos)[i].mutex, NULL);
		(*philos)[i].attr = attr;
		(*philos)[i].data = data;
	}
	return (1);
}
