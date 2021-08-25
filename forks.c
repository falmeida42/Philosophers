/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:16:28 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/25 21:04:36 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	init_forks(t_state *philo)
{
	int	i;
	i = 0;
	philo->forks = malloc(sizeof(bool) * philo->n_philos);
	while (i < philo->n_philos)
	{
		philo->forks[i] = true;
		i++;
	}
}

void	pick_fork(t_state *philo, int hand)
{
	int	current;

	current = get_time() - philo->t_start;
	if (philo->forks[hand] == 1)
	{
		printf("[%d]\t X\t has taken a fork\n", current);
		philo->forks[hand] = 0;
	}
}

void	release_fork(t_state *philo, int hand)
{
	int	current;

	current = get_time() - philo->t_start;
	if (philo->forks[hand] == 0)
	{
		printf("[%d]\t X\t has release a fork\n", current);
		philo->forks[hand] = 1;
	}
}
