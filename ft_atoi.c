/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: falmeida <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 14:17:14 by falmeida          #+#    #+#             */
/*   Updated: 2021/03/03 14:34:12 by falmeida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int nome;
	int sinal;

	nome = 0;
	sinal = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
	{
		str++;
	}
	if (*str == '-')
	{
		sinal = sinal * -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nome = (nome * 10) + (*str++ - '0');
	}
	return (nome * sinal);
}
