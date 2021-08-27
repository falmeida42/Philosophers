/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:09:49 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/27 18:37:53 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_satisfied(t_philo *philo)
{
	int	current;

	current = get_time() - state.t_start;
	if (philo->n_eat == state.eat_rep)
	{
		printer(philo, current, 'a', 0);
		state.all_satisfated--;
		philo->can_print = false;
	}
	if (state.all_satisfated == 0)
		exit(0);
}

void	check_die(t_philo *philo)
{
	int	current;

	current = get_time() - state.t_start;
	if (philo->last_eat + state.t_die < current)
	{
		printer(philo, current, 'd', 0);
		exit (0);
	}
}
