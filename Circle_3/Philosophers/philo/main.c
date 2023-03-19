/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 19:27:42 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/20 01:04:29 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	error(char *message)
{
	printf(RED"%s\n"RESET, message);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo_data	data;
	t_philo			*philos;

	if (argc != 5 && argc != 6)
		return (error("usage: num_of_philosophers time_to_die time_to_eat "
				"time_to_sleep [num_of_times_to_must_eat]"));
	philos = NULL;
	if (init_philo_data(&data, argv) == 0 || init_philos(&philos, &data) == 0)
	{
		free_all(&philos);
		return (error("error: initialization"));
	}
	simulate(philos);
	free_all(&philos);
	return (0);
}
