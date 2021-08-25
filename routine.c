/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:06:53 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/25 21:06:13 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_state *philo)
{
	int	current;
	int	thinking;

	current = get_time() - philo->t_start;
	thinking = current;
	printf("[%d]\t X\t is thinking\n", current);
	while (current <  thinking + philo->t_sleep)
		current = get_time() - philo->t_start;
	check_die(philo);
}

void	sleeping(t_state *philo)
{
	int	current;
	int	sleeping;

	current = get_time() - philo->t_start;
	sleeping = current;
	printf("[%d]\t X\t is sleeping\n", current);
 	while (current < sleeping + philo->t_sleep)
	current = get_time() - philo->t_start;
	check_die(philo);
	thinking(philo);
}

void	eating(t_state *philo)
{
	int	current;
	int	eating;
	int time;

	current = get_time() - philo->t_start;
	eating = current;
	philo->philos->last_eat = current;
	printf("[%d]\t X\t is eating\n", current);
	while (current < eating + philo->t_eat)
	{
		current = get_time() - philo->t_start;
		time = get_time();
	}
	release_fork(philo, philo->philos->fork_l);
	release_fork(philo, philo->philos->fork_r);
	check_die(philo);
	philo->philos->n_eat++;
	check_satisfied(philo);
	sleeping(philo);
}
