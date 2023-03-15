/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 21:40:23 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/15 22:48:09 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error(char *message)
{
	printf(RED"%s\n"RESET, message);
	return (1);
}

void	free_all(t_philo **philos)
{
	const int			n = (*philos)[0].attr->num_of_philosophers;
	int					i;

	i = -1;
	while (++i < n)
	{
		pthread_mutex_destroy(&(*philos)[i].mutex);
		pthread_mutex_destroy(&(*philos)[0].data->fork_mutex[i]);
	}
	pthread_mutex_destroy(&(*philos)[0].data->print_mutex);
	free((*philos)[0].data->fork_mutex);
	free(*philos);
}

void	check_leak(void) ///////////////////////////////////////////////////////
{
	system("leaks philo | grep leaked");
}

int	main(int argc, char **argv)
{
	t_common_attr	attr;
	t_shared_data	data;
	t_philo			*philos;

	atexit(check_leak); ////////////////////////////////////////////////////////
	if (argc != 5 && argc != 6)
		return (error("usage: num_of_philosophers time_to_die time_to_eat "
				"time_to_sleep [num_of_times_to_must_eat]"));
	if (init_common_attr(&attr, argv) == 0
		|| init_shared_data(&data, attr.num_of_philosophers) == 0
		|| init_philos(&philos, &attr, &data) == 0)
	{
		free_all(&philos);
		return (error("initialization failed"));
	}
	simulate(&philos);
	free_all(&philos);
	return (1);
}
