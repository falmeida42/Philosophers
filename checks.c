/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:09:49 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/24 22:10:34 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	check_satisfied(t_state *philo)
{
	int	current;

	current = get_time() - philo->t_start;
	if (philo->philos->n_eat == philo->eat_rep)
	{
		printf("[%d]\t X\t is satisfied\n", current);
		exit (0);
	}
}

void	check_die(t_state *philo)
{
	int	current;

	current = get_time() - philo->t_start;
	if (philo->philos->last_eat + philo->t_die < current)
	{
		printf("[%d]\t X\t is die\n", current);
		exit (0);
	}
}
