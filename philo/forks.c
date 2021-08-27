/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:16:28 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/27 21:33:33 by falmeida         ###   ########.fr       */
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
		state->forks[i] = true;
		i++;
	}
}

void	pick_fork(t_philo *philo, int hand)
{
	int	current;

	pthread_mutex_lock(&philo->lock);
	current = get_time() - philo->state->t_start;
	if (philo->state->forks[hand] == 1)
	{
		printer(philo, current, 'f', hand);
		philo->state->forks[hand] = 0;
		philo->n_forks++;
	}
	pthread_mutex_unlock(&philo->lock);
}

void	release_fork(t_philo *philo, int hand)
{
	int	current;

	current = get_time() - philo->state->t_start;
	if (philo->state->forks[hand] == 0)
	{
		printer(philo, current, 'r', hand);
		philo->state->forks[hand] = 1;
		philo->n_forks--;
	}
}
