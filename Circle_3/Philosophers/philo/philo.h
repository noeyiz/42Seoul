/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jikoo <jikoo@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 16:13:57 by jikoo             #+#    #+#             */
/*   Updated: 2023/03/17 20:56:25 by jikoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h> ////////////////////////////////////////////////////////////
# include <stdlib.h> ///////////////////////////////////////////////////////////

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

typedef struct s_philo_data
{
	int				end_flag;
	int				num_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_to_must_eat;
	int				*eat_count;
	long long		start_time;
	long long		*last_eat_time;
	pthread_mutex_t	end_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	*eat_mutex;
	pthread_mutex_t	*fork_mutex;
}	t_philo_data;

typedef struct s_philo
{
	int				id;
	int				left;
	int				right;
	pthread_t		thread;
	t_philo_data	*data;
}	t_philo;

/* init_free.c */
int			init_philo_data(t_philo_data *data, char **argv);
int			init_philos(t_philo **philos, t_philo_data *data);
void		free_all(t_philo **philos);

/* simulate.c */
void		monitoring(t_philo_data *data);
void		simulate(t_philo *philos);

/* routine.c */
void		*routine(void *philosophers);

/* utils.c */
long long	get_milisecond(long long start_time);
void		msleep(long long target_time);
void		print_state(pthread_mutex_t *print_mutex, long long start_time,
				int philo_id, char *state);
void		print_die(pthread_mutex_t *print_mutex, long long start_time,
				int philo_id);
void		print_done(pthread_mutex_t *print_mutex);
				
#endif