/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:24:47 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/30 18:10:40 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

typedef struct	s_state {

	uint64_t		t_start;
	int		n_philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		eat_rep;
	bool	*forks;
	int		all_satisfated;
	pthread_mutex_t	die_lock;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	*lock;
}				t_state;

typedef struct	s_philo {
	int	position;
	int	fork_r;
	int	fork_l;
	int	sleep;
	int	think;
	int	n_eat;
	int	last_eat;
	int	n_forks;
	int	init;
	bool	can_print;
	pthread_t	p;
	t_state	*state;
} t_philo;

//routine.c
void	check_satisfied(t_philo *philo);
void	thinking(t_philo *philo);
void	sleeping(t_philo *philo);
void	eating(t_philo *philo);
//routine.c

//utils.c
int	ft_atoi(const char *str);
uint64_t get_time(void);
//utils.c

//checks.c
int		ft_exit(t_philo *philo);
void	check_satisfied(t_philo *philo);
void	check_die(t_philo *philo);
//checks.c

//forks.c
void	init_forks(t_state *state);
void	pick_fork(t_philo *philo, int hand);
void	release_fork(t_philo *philo, int hand);
//forks.c

void	printer(t_philo *philo, char print, int hand);


#endif
