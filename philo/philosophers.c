/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 21:31:22 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/27 21:34:43 by falmeida         ###   ########.fr       */
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
		philo[i].eat = 0;
		philo[i].die = 0;
		philo[i].fork_l = i;
		philo[i].fork_r = (i + 1) % state->n_philos;
		philo[i].sleep = 0;
		philo[i].think = 0;
		philo[i].n_eat = 0;
		philo[i].n_forks = 0;
		philo[i].init = 0;
		philo[i].can_print = true;
		philo[i].state = state;
		pthread_mutex_init(&philo[i].lock, NULL);
		i++;
	}
}

void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;

	while (1)
	{
		if (philo->init == 0)
		{
			while (philo->n_forks != 2)
			{
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
				check_die(philo);
			}
			philo->init++;
		}
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
}

int	main(int argc, char **argv)
{
	t_state		state;
	pthread_t	*philos;
	t_philo		*philo;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	philos = NULL;
	init(&state, argc, argv);
	state.t_start = get_time();
	init_forks(&state);
	philo = malloc(sizeof(t_philo) * state.n_philos);
	init_philosopher(&state, philo);
	philos = malloc(sizeof(pthread_t) * state.n_philos);
	i = 0;
	while (i < state.n_philos)
	{
		pthread_create(&philos[i], NULL, &routine, &philo[i]);
		i++;
	}
	i = 0;
	while (i < state.n_philos)
	{
		pthread_join(philos[i], NULL);
		i++;
	}
	return (0);
}
