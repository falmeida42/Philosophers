/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 17:57:47 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/31 17:23:29 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	printer(t_philo *philo, char print)
{
	int	current;


	pthread_mutex_lock(&philo->state->print_lock);
	current = get_time() - philo->state->t_start;
	if (philo->can_print == true && philo->state->is_die == true)
	{
		if (print == 's')
			printf("%d %d is sleeping\n", current, philo->position + 1);
		else if (print == 't')
			printf("%d %d is thinking\n", current, philo->position + 1);
		else if (print == 'e')
			printf("%d %d is eating\n", current, philo->position + 1);
		else if (print == 'd')
			printf("%d %d died\n", current, philo->position + 1);
		else if (print == 'f')
			printf("%d %d has taken a fork\n", current, philo->position + 1);
	}
	pthread_mutex_unlock(&philo->state->print_lock);
}
