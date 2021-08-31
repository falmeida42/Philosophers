/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:31:22 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/31 14:29:18 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosopher(t_state *state, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < state->n_philos)
	{
		philo[i].position = i + 1;
		philo[i].fork_l = i;
		philo[i].fork_r = (i + 1) % state->n_philos;
		philo[i].sleep = 0;
		philo[i].think = 0;
		philo[i].n_eat = 0;
		philo[i].n_forks = 0;
		philo[i].init = 0;
		philo[i].last_eat = 0;
		philo[i].can_print = true;
		philo[i].state = state;
		i++;
	}
}

void	start_pick_fork(t_philo *philo)
{
	if (check_die(philo) == 0)
		return ;
	if (philo->position % 2 > 0)
	{
		pick_fork(philo, philo->fork_r);
		pick_fork(philo, philo->fork_l);
	}
	else
	{
		usleep(100);
		pick_fork(philo, philo->fork_l);
		pick_fork(philo, philo->fork_r);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (philo->state->is_die == 1)
	{
		if (philo->init == 0)
		{
			while (philo->n_forks != 2 && philo->state->is_die == 1)
				start_pick_fork(philo);
			philo->init++;
		}
		check_die(philo);
		if (philo->state->is_die == 0)
			return (0);
		eating(philo);
		check_die(philo);
	}
	return (0);
}

void	init(t_state *state, int argc, char **argv)
{
	state->n_philos = ft_atoi(argv[1]);
	state->t_die = ft_atoi(argv[2]);
	state->t_eat = ft_atoi(argv[3]);
	state->t_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		state->eat_rep = ft_atoi(argv[5]);
	else
		state->eat_rep = -1;
	state->all_satisfated = state->n_philos;
	state->lock = malloc(sizeof(pthread_mutex_t) * state->n_philos);
	pthread_mutex_init(&state->die_lock, NULL);
	pthread_mutex_init(&state->print_lock, NULL);
	state->is_die = 1;
}

int	main(int argc, char **argv)
{
	t_state		state;
	t_philo		*philo;
	int			i;

	if (argc < 5 || argc > 6 || ft_atoi(argv[1]) == 0)
		return (1);
	state.t_start = get_time();
	init(&state, argc, argv);
	init_forks(&state);
	philo = malloc(sizeof(t_philo) * state.n_philos);
	init_philosopher(&state, philo);
	i = -1;
	while (++i < state.n_philos)
		pthread_create(&philo[i].p, NULL, &routine, &philo[i]);
	i = -1;
	while (++i < state.n_philos)
		pthread_join(philo[i].p, NULL);
	ft_exit(philo);
	return (0);
}
