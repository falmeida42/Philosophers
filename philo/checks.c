/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:09:49 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/30 18:17:40 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_exit(t_philo *philo)
{
	philo = NULL;
	return (0);
}

void	check_satisfied(t_philo *philo)
{
	int	current;

	current = get_time() - philo->state->t_start;
	if (philo->n_eat == philo->state->eat_rep)
	{
		printer(philo, 'a', 0);
		philo->state->all_satisfated--;
		philo->can_print = false;
	}
	if (philo->state->all_satisfated == 0)
	{
		ft_exit(philo);
		exit(0);
	}
}

void	check_die(t_philo *philo)
{
	int	current;

	current = get_time() - philo->state->t_start;
	if (philo->last_eat + philo->state->t_die < current)
	{
		printer(philo, 'd', 0);
		ft_exit(philo);
		exit(0);
	}
}
