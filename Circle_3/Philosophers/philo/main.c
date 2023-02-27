/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 16:24:51 by jikoo             #+#    #+#             */
/*   Updated: 2023/02/27 21:43:11 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_all(t_info *info, pthread_mutex_t **forks)
{
	int	i;
	
	if (info->mutex)
	{
		pthread_mutex_destroy(info->mutex);
		free(info->mutex);
	}
	if (*forks)
	{
		i = 0;
		while ((++i < info->num_of_philosophers))
			pthread_mutex_destroy(&(*forks)[i]);
		free(*forks);
		*forks = NULL;
	}
}

void	check_leak(void) ///////////////////////////////////////////////////////
{
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_info			info;
	pthread_mutex_t	*forks;
	t_philo			*philos;

	atexit(&check_leak); ///////////////////////////////////////////////////////
	if (argc != 5 && argc != 6)
		return (0);
	if (ft_init_info(&info, argv) == FAILURE
		|| ft_init_forks(&forks, info.num_of_philosophers) == FAILURE
		|| ft_init_philos(&philos, &info, &forks) == FAILURE)
	{
		ft_free_all(&info, &forks);
		return (0);
	}
	ft_free_all(&info, &forks);
	return (0);
}
