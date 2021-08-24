/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:24:47 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/24 22:16:21 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philos {
	int	position;
	int	eat;
	int	t_limit;
	int	die;
	int	fork_r;
	int	fork_l;
	int	sleep;
	int	think;
	int	n_eat;
	int	last_eat;
} t_philos;

typedef struct	s_state {

	int		t_start;
	int		t_end;
	int		n_philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		eat_rep;
	t_philos	*philos;
}				t_state;

//routine.c
void	check_satisfied(t_state *philo);
void	thinking(t_state *philo);
void	sleeping(t_state *philo);
void	eating(t_state *philo);
//routine.c

//utils.c
int	ft_atoi(const char *str);
uint64_t get_time(void);
//utils.c

//checks.c
void	check_satisfied(t_state *philo);
void	check_die(t_state *philo);
//checks.c

//forks.c

//forks.c

#endif
