/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:47:37 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/10 20:33:07 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_atoi(char *str)
{
	int			sign;
	long long	num;

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

int	init_info(t_info *info, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->num_of_philosophers = ph_atoi(argv[1]);
	info->time_to_die = ph_atoi(argv[2]);
	info->time_to_eat = ph_atoi(argv[3]);
	info->time_to_sleep = ph_atoi(argv[4]);
	if (argv[5])
		info->num_of_times_to_must_eat = ph_atoi(argv[5]);
	if (info->num_of_philosophers <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| info->num_of_times_to_must_eat < 0)
		return (FAILURE);
	gettimeofday(&info->start_time, NULL);
	info->mutex = malloc(sizeof(pthread_mutex_t));
	if (info->mutex == NULL)
		return (FAILURE);
	if (pthread_mutex_init(info->mutex, NULL))
		return (FAILURE);
	return (SUCCESS);
}

int	init_forks(t_fork **forks, int num)
{
	int	i;

	*forks = malloc(sizeof(t_fork) * num);
	if (*forks == NULL)
		return (FAILURE);
	i = -1;
	while (++i < num)
	{
		(*forks)[i].is_available = TRUE;
		(*forks)[i].mutex = malloc(sizeof(pthread_mutex_t));
		if ((*forks)[i].mutex == NULL)
			return (FAILURE);
		if (pthread_mutex_init((*forks)[i].mutex, NULL))
			return (FAILURE);
	}
	return (SUCCESS);
}

int	init_philos(t_philo **philos, t_info info, t_fork *forks)
{
	int	i;
	int	num;

	num = info.num_of_philosophers;
	*philos = malloc(sizeof(t_philo) * num);
	if (*philos == NULL)
		return (FAILURE);
	i = -1;
	while (++i < num)
	{
		(*philos)[i].id = i;
		(*philos)[i].eat_cnt = 0;
		(*philos)[i].status = FORK;
		(*philos)[i].last_eat_time = info.start_time;
		(*philos)[i].left_fork = &forks[i];
		(*philos)[i].right_fork = &forks[(i + 1) % num];
		(*philos)[i].mutex = malloc(sizeof(pthread_mutex_t));
		if ((*philos)[i].mutex == NULL)
			return (FAILURE);
		if (pthread_mutex_init((*philos)[i].mutex, NULL))
			return (FAILURE);
	}
	return (SUCCESS);
}
