/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:09:49 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/26 18:59:15 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_satisfied(t_philo *philo)
{
	int	current;

	current = get_time() - state.t_start;
	if (philo->n_eat == state.eat_rep)
	{
		printf("[%d]\t X\t is satisfied\n", current);
		exit (0);
	}
}

void	check_die(t_philo *philo)
{
	int	current;

	current = get_time() - state.t_start;
	if (philo->last_eat + state.t_die < current)
	{
		printf("[%d]\t X\t is die\n", current);
		exit (0);
	}
}
