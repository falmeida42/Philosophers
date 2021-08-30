/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:16:28 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/30 18:43:43 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(t_state *state)
{
	int	i;

	i = 0;
	state->forks = malloc(sizeof(bool) * state->n_philos);
	while (i < state->n_philos)
	{
		pthread_mutex_init(&state->lock[i], NULL);
		state->forks[i] = true;
		i++;
	}
}

void	pick_fork(t_philo *philo, int hand)
{
	int	current;

	pthread_mutex_lock(&philo->state->lock[hand]);
	current = get_time() - philo->state->t_start;
	if (philo->state->forks[hand] == 1)
	{
		printer(philo, 'f');
		philo->state->forks[hand] = 0;
		philo->n_forks++;
	}
	pthread_mutex_unlock(&philo->state->lock[hand]);
}

void	release_fork(t_philo *philo, int hand)
{
	int	current;

	current = get_time() - philo->state->t_start;
	if (philo->state->forks[hand] == 0)
	{
		philo->state->forks[hand] = 1;
		philo->n_forks--;
	}
}
