/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:16:28 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/31 18:12:01 by falmeida         ###   ########.fr       */
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
	check_satisfied(philo);
	if (philo->state->forks[hand] == true)
	{
		printer(philo, 'f');
		philo->state->forks[hand] = false;
		philo->n_forks++;
	}
	pthread_mutex_unlock(&philo->state->lock[hand]);
}

void	release_fork(t_philo *philo, int hand)
{
	int	current;

	current = get_time() - philo->state->t_start;
	if (philo->state->forks[hand] == false)
	{
		philo->state->forks[hand] = true;
		philo->n_forks--;
	}
}
