/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:31:01 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/16 19:17:01 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "philo.h"

long long	get_milisecond(long long start_time)
{
	struct timeval	time;
	long long		current_time;

	gettimeofday(&time, NULL);
	current_time = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (current_time - start_time);
}

void	msleep(long long target_time)
{
	long long	start_time;

	start_time = get_milisecond(0);
	while (target_time > get_milisecond(0) - start_time)
		usleep(100);
}

void	print_state(pthread_mutex_t *print_mutex, long long start_time,
				int philo_id, char *state)
{
	pthread_mutex_lock(print_mutex);
	printf("%lld %d %s\n", get_milisecond(start_time), philo_id + 1, state);
	pthread_mutex_unlock(print_mutex);
}
