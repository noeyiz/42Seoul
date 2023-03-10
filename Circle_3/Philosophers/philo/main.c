/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:24:51 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/10 20:39:38 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_all(t_info *info, t_fork **forks, t_philo **philos)
{
	int	i;
	
	if (info->mutex)
	{
		pthread_mutex_destroy(info->mutex);
		free(info->mutex);
	}
	i = -1;
	while (++i < info->num_of_philosophers)
	{
		if (*forks)
		{
			pthread_mutex_destroy((*forks)[i].mutex);
			free((*forks)[i].mutex);
		}
		if (*philos)
		{
			pthread_mutex_destroy((*philos)[i].mutex);
			free((*philos)[i].mutex);
		}
	}
	free(*forks);
	free(*philos);
}

void	check_leak(void) ///////////////////////////////////////////////////////
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_fork	*forks;
	t_philo	*philos;

	atexit(&check_leak); ///////////////////////////////////////////////////////
	if (argc != 5 && argc != 6)
		return (0);
	if (init_info(&info, argv) == FAILURE
		|| init_forks(&forks, info.num_of_philosophers) == FAILURE
		|| init_philos(&philos, info, forks) == FAILURE)
	{
		free_all(&info, &forks, &philos);
		return (0);
	}
	free_all(&info, &forks, &philos);
	return (0);
}
