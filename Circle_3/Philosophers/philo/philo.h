/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:58:36 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/10 20:30:05 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* pthread_create, pthread_detach, pthread_join, pthread_mutex_init, 
	pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock */
# include <pthread.h>
/* printf */
# include <stdio.h>
/* malloc, free */
# include <stdlib.h>
/* memset */
# include <string.h>
/* gettimeofday */
# include <sys/time.h>
/* write, usleep */
# include <unistd.h>

# define SUCCESS 1
# define FAILURE 0
# define TRUE 1
# define FALSE 0

typedef enum e_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_status;

typedef struct s_fork
{
	int				is_available;
	pthread_mutex_t	*mutex;
}	t_fork;

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	t_status		status;
	pthread_t		thread;
	struct timeval	last_eat_time;
	t_fork			*left_fork;
	t_fork			*right_fork;
	pthread_mutex_t	*mutex;
}	t_philo;

typedef struct s_info
{
	int				end_flag;
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_to_must_eat;
	struct timeval	start_time;
	pthread_mutex_t	*mutex;
}	t_info;

/* init.c */
int	init_info(t_info *info, char **argv);
int	init_forks(t_fork **forks, int num);
int	init_philos(t_philo **philos, t_info info, t_fork *forks);

#endif
