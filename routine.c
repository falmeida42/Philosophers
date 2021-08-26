/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 22:06:53 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/26 18:50:01 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	thinking(t_philo *philo)
{
	int	current;
	int	thinking;

	current = get_time() - state.t_start;
	thinking = current;
	printf("[%d]\t X\t is thinking\n", current);
	while (current <  thinking + state.t_sleep)
		current = get_time() - state.t_start;
	check_die(philo);
}

void	sleeping(t_philo *philo)
{
	int	current;
	int	sleeping;

	current = get_time() - state.t_start;
	sleeping = current;
	printf("[%d]\t X\t is sleeping\n", current);
 	while (current < sleeping + state.t_sleep)
	current = get_time() - state.t_start;
	check_die(philo);
	thinking(philo);
}

void	eating(t_philo *philo)
{
	int	current;
	int	eating;
	int time;

	//if (philo->n_forks < 2)
	//	return ;
	current = get_time() - state.t_start;
	eating = current;
	philo->last_eat = current;
	printf("[%d]\t X\t is eating\n", current);
	while (current < eating + state.t_eat)
	{
		current = get_time() - state.t_start;
		time = get_time();
	}
	//release_fork(philo, philo->fork_l);
	//release_fork(philo, philo->fork_r);
	check_die(philo);
	philo->n_eat++;
	check_satisfied(philo);
	sleeping(philo);
}
