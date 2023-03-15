/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:49:47 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/16 01:23:46 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK		"has taken a fork"
# define EAT		"is eating"
# define SLEEP		"is sleeping"
# define THINK		"is thinking"
# define DIE		"died"

# define RESET		"\033[0m"
# define GRAY		"\033[1;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[1;93m"
# define BLUE		"\033[1;94m"
# define MAGENTA	"\033[1;95m"
# define CYAN		"\033[1;96m"

typedef struct s_common_attr
{
	int	num_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_times_to_must_eat;
}	t_common_attr;

typedef struct s_shared_data
{
	long long		start_time;
	pthread_mutex_t	*fork_mutex;
	pthread_mutex_t	print_mutex;
}	t_shared_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long long		last_eat_time;
	pthread_t		thread;
	pthread_mutex_t	mutex;
	t_common_attr	*attr;
	t_shared_data	*data;
}	t_philo;

int			init_common_attr(t_common_attr *attr, char **argv);
int			init_shared_data(t_shared_data *data, int n);
int			init_philos(t_philo **philos, t_common_attr *attr, \
						t_shared_data *data);

int			check_end(t_shared_data *data);
void		simulate(t_philo *philos);
void		*routine(void *philosopher);

long long	get_milisecond(long long start_time);
void		msleep(long long time);
void		print_state(pthread_mutex_t *print, long long start_time, \
						int philo_id, char *state);

#endif