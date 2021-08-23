/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:28:02 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/23 19:52:33 by falmeida         ###   ########.fr       */
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
		state->t_eat_rep = ft_atoi(argv[5]);
	else
		state->t_eat_rep = 0;
	state->philos = malloc(sizeof(t_philos) * state->n_philos);
	init_philosopher(state);
}

uint64_t get_time(void)
{
	static struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	main(int argc, char **argv)
{
	t_state state;
	pthread_t	tid;
	int			i;

	if (argc < 5 || argc > 6)
		return (1);
	init(&state, argc, argv);
	state.start = get_time();
	printf("%d\n", state.start);
	printf("%d\n", state.philos->t_limit);
	usleep(300);
	return (0);
}
