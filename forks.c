/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:16:28 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/26 19:26:31 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks()
{
	int	i;
	i = 0;
	state.forks = malloc(sizeof(bool) * state.n_philos);
	while (i < state.n_philos)
	{
		state.forks[i] = true;
		i++;
	}
}

void	pick_fork(t_philo *philo, int hand)
{
	int	current;

	pthread_mutex_lock(&state.lock);
	current = get_time() - state.t_start;
	if (state.forks[hand] == 1)
	{
		printf("[%d]\t %d\t has taken a fork %d\n", current, philo->position, hand);
		state.forks[hand] = 0;
		philo->n_forks++;
	}
	pthread_mutex_unlock(&state.lock);
}

void	release_fork(t_philo *philo, int hand)
{
	int	current;

	current = get_time() - state.t_start;
	if (state.forks[hand] == 0)
	{
		printf("[%d]\t %d\t has release a fork %d\n", current, philo->position, hand);
		state.forks[hand] = 1;
		philo->n_forks--;
	}
}
