/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:16:28 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/26 18:49:24 by falmeida         ###   ########.fr       */
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

	current = get_time() - state.t_start;
	if (state.forks[hand] == 1)
	{
		printf("[%d]\t X\t has taken a fork\n", current);
		state.forks[hand] = 0;
		philo->n_forks++;
	}
}

void	release_fork(t_philo *philo, int hand)
{
	int	current;

	current = get_time() - state.t_start;
	if (state.forks[hand] == 0)
	{
		printf("[%d]\t X\t has release a fork\n", current);
		state.forks[hand] = 1;
		philo->n_forks--;
	}
}
