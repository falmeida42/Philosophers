/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:57:47 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/31 12:50:09 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printer(t_philo *philo, char print)
{
	int current;

	pthread_mutex_lock(&philo->state->print_lock);
	current = get_time() - philo->state->t_start;
	if (philo->can_print == true && philo->state->is_die == true)
	{
		if (print == 't')
			printf("[%d]\t %d\t is thinking\n", current, philo->position);
		else if (print == 's')
			printf("[%d]\t %d\t is sleeping\n", current, philo->position);
		else if (print == 'e')
			printf("[%d]\t %d\t is eating\n", current, philo->position);
		else if (print == 'a')
			printf("[%d]\t %d\t is satisfied\n", current, philo->position);
		else if (print == 'd')
			printf("[%d]\t %d\t is die\n", current, philo->position);
		else if (print == 'f')
			printf("[%d]\t %d\t has taken a fork\n", current,
				 philo->position);
	}
	pthread_mutex_unlock(&philo->state->print_lock);
}
