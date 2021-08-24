/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <falmeida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 11:28:02 by falmeida          #+#    #+#             */
/*   Updated: 2021/08/24 20:31:36 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	init_philosopher(t_state *state)
{
	int i;

	i = 0;

	while (i < state->n_philos)
	{
		state->philos[i].position = i;
		state->philos[i].eat = 0;
		state->philos[i].die = 0;
		state->philos[i].fork_l = i;
		state->philos[i].fork_r = (i + 1) % state->n_philos;
		state->philos[i].sleep = 0;
		state->philos[i].think = 0;
		state->philos[i].n_eat = 0;
		i++;
	}
}

void	init(t_state *state, int argc, char **argv)
{
	state->n_philos = ft_atoi(argv[1]);
	state->t_die = ft_atoi(argv[2]);
	state->t_eat = ft_atoi(argv[3]);
	state->t_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		state->eat_rep = ft_atoi(argv[5]);
	else
		state->eat_rep = 0;
	state->philos = malloc(sizeof(t_philos) * state->n_philos);
	init_philosopher(state);
}

uint64_t get_time(void)
{
	static struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
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

void	eating(t_state *philo)
{
	int	current;
	int	eating;

	current = get_time() - philo->t_start;
	eating = current;
	philo->philos->last_eat = current;
	printf("[%d]\t X\t is eating\n", current);
	while (current < eating + philo->t_eat)
		current = get_time() - philo->t_start;
	check_die(philo);
	philo->philos->n_eat++;
	check_satisfied(philo);
	sleeping(philo);
}

void	*routine(void *arg)
{
	while (1)
	eating(arg);
	return (0);
}

int	main(int argc, char **argv)
{
	t_state		state;
	pthread_t	philo;

	if (argc < 5 || argc > 6)
		return (1);
	init(&state, argc, argv);
	state.t_start = get_time();
	state.t_end = get_time() - state.t_start;
	pthread_create(&philo, NULL, &routine, (void *)&state);

	return (0);
}
