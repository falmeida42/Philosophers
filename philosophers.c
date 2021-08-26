/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:28:02 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/26 17:53:03 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_philosopher(t_state *state)
{
	int i;

	i = 0;

	while (i < state->n_philos)
	{
		state->philos[i].position = i;
		state->philos[i].eat = 0;
		state->philos[i].die = 0;
		state->philos[i].fork_l = i;
		state->philos[i].fork_r = (i + 1) % state->n_philos;
		state->philos[i].sleep = 0;
		state->philos[i].think = 0;
		state->philos[i].n_eat = 0;
		state->philos[i].n_forks = 0;
		i++;
	}
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
		state->eat_rep = 0;
	state->philos = malloc(sizeof(t_philos) * state->n_philos);
	init_philosopher(state);
}

void	*routine(void *arg)
{
	t_state *state = (t_state *)arg;

	while (1)
	{
		pick_fork(state, state->philos->fork_l);
		pick_fork(state, state->philos->fork_r);
		eating(state);
		check_die(state);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_state		state;
	pthread_t	*philo;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	philo = NULL;
	init(&state, argc, argv);
	state.t_start = get_time();
	init_forks(&state);
	philo = malloc(sizeof(pthread_t) * state.n_philos);
	i = 0;
	while (i < state.n_philos)
	{
		pthread_create(&philo[i], NULL, &routine, &state);
		i++;
	}
	i = 0;
	while (i < state.n_philos)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
	return (0);
}
