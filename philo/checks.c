/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:09:49 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/27 21:16:41 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_satisfied(t_philo *philo)
{
	int	current;

	current = get_time() - philo->state->t_start;
	if (philo->n_eat == philo->state->eat_rep)
	{
		printer(philo, current, 'a', 0);
		philo->state->all_satisfated--;
		philo->can_print = false;
	}
	if (philo->state->all_satisfated == 0)
		exit(0);
}

void	check_die(t_philo *philo)
{
	int	current;

	current = get_time() - philo->state->t_start;
	if (philo->last_eat + philo->state->t_die < current)
	{
		printer(philo, current, 'd', 0);
		exit (0);
	}
}
