/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:09:49 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/31 12:57:29 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_exit(t_philo *philo)
{
	free(philo->state->lock);
	philo->state->lock = NULL;
	free(philo->state->forks);
	philo->state->forks = NULL;
	free(philo);
	philo = NULL;
}

void	check_satisfied(t_philo *philo)
{
	int	current;

	current = get_time() - philo->state->t_start;
	if (philo->n_eat == philo->state->eat_rep)
	{
		printer(philo, 'a');
		philo->state->all_satisfated--;
		philo->can_print = false;
	}
	if (philo->state->all_satisfated == 0)
	{
		exit(0);
	}
}

int	check_die(t_philo *philo)
{
	int	current;
	int	result;

	result = 1;
	pthread_mutex_lock(&philo->state->die_lock);
	current = get_time() - philo->state->t_start;
	if (philo->last_eat + philo->state->t_die < current)
	{
		printer(philo, 'd');
		philo->state->is_die = false;
		result = 0;
	}
	pthread_mutex_unlock(&philo->state->die_lock);
	return (result);
}
