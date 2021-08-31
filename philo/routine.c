/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:06:53 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/31 14:31:54 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *philo)
{
	int	current;
	int	thinking;

	check_die(philo);
	if (philo->state->is_die == 0)
		return ;
	current = get_time() - philo->state->t_start;
	thinking = current;
	printer(philo, 't');
	while (philo->n_forks < 2 && philo->state->is_die == 1)
	{
		if (philo->position % 2 > 0)
		{
			pick_fork(philo, philo->fork_l);
			pick_fork(philo, philo->fork_r);
		}
		else
		{
			pick_fork(philo, philo->fork_r);
			pick_fork(philo, philo->fork_l);
		}
		check_die(philo);
		if (philo->state->is_die == 0)
			return ;
	}
}

void	sleeping(t_philo *philo)
{
	int	current;
	int	sleeping;

	check_die(philo);
	if (philo->state->is_die == 0)
		return ;
	current = get_time() - philo->state->t_start;
	sleeping = current;
	printer(philo, 's');
	while (current < sleeping + philo->state->t_sleep)
	{
		current = get_time() - philo->state->t_start;
		check_die(philo);
		if (philo->state->is_die == 0)
			return ;
	}
	thinking(philo);
}

void	eating(t_philo *philo)
{
	int	current;
	int	eating;

	check_die(philo);
	if (philo->n_forks < 2 || philo->state->is_die == 0)
		return ;
	current = get_time() - philo->state->t_start;
	eating = current;
	printer(philo, 'e');
	philo->last_eat = current;
	while (current < eating + philo->state->t_eat)
	{
		current = get_time() - philo->state->t_start;
		check_die(philo);
		if (philo->state->is_die == 0)
			return ;
	}
	check_satisfied(philo);
	release_fork(philo, philo->fork_l);
	release_fork(philo, philo->fork_r);
	check_die(philo);
	if (philo->state->is_die == 0)
		return ;
	philo->n_eat++;
	sleeping(philo);
}
