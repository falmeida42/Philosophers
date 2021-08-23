/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:28:02 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/23 11:38:06 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*sample(){
	printf("Hi, i'm Philosopher\n");
	sleep(1);
	printf("Bye\n");
}

int	main(int argc, char **argv)
{
	pthread_t	philo1;
	pthread_t	philo2;

	pthread_create(&philo1, NULL, &sample, NULL);
	pthread_create(&philo2, NULL, &sample, NULL);
	pthread_join(philo1, NULL);
	pthread_join(philo2, NULL);

	return (0);
}
