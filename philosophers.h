/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:24:47 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/23 13:31:52 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct	s_philos {
	int	position;
	int	eat;
	int	die;
	int	fork_r;
	int	fork_l;
	int	sleep;
	int	think;
	int	n_eat;
} t_philos;

typedef struct	s_state {

	int		n_philos;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		t_eat_rep;
	t_philos	*philos;
}				t_state;



int	ft_atoi(const char *str);

#endif
