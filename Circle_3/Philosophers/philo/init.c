/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:47:37 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/27 21:26:18 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_ph_atoi(char *str)
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

int	ft_init_info(t_info *info, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->num_of_philosophers = ft_ph_atoi(argv[1]);
	info->time_to_die = ft_ph_atoi(argv[2]);
	info->time_to_eat = ft_ph_atoi(argv[3]);
	info->time_to_sleep = ft_ph_atoi(argv[4]);
	if (argv[5])
		info->num_of_times_to_must_eat = ft_ph_atoi(argv[5]);
	if (info->num_of_philosophers <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0
		|| info->num_of_times_to_must_eat < 0)
		return (FAILURE);
	gettimeofday(&info->start_time, NULL);
	info->mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	if (info->mutex == NULL)
		return (FAILURE);
	if (pthread_mutex_init(info->mutex, NULL))
		return (FAILURE);
	return (SUCCESS);
}

int	ft_init_forks(pthread_mutex_t **forks, int num)
{
	int	i;

	*forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * num);
	if (*forks == NULL)
		return (FAILURE);
	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&(*forks)[i], NULL))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	ft_init_philos(t_philo **philos, t_info *info, pthread_mutex_t **forks)
{
	(void)info;
	(void)forks;
	(void)philos;
	return (SUCCESS);
}
