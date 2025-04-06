/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:38:10 by ckappe            #+#    #+#             */
/*   Updated: 2025/04/06 17:54:57 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	if (!str1 || !str2)
		return (1);
	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (str2[i] - str1[i]);
		i++;
	}
	return (str1[i] - str2[i]);
}

int	close_window(t_fractol *fractol)
{
	(void)fractol;
	exit(EXIT_SUCCESS);
}

static int	handle_sign(char *num, int *i)
{
	int	sign;

	sign = 1;
	if (num[*i] == '-' || num[*i] == '+')
	{
		if (num[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

int	julia_in(char *num)
{
	int	i;
	int	has_decimal;

	i = 0;
	has_decimal = 0;
	if (num[i] == '-' || num[i] == '+')
		i++;
	while (num[i])
	{
		if (num[i] == '.')
		{
			if (has_decimal)
				return (0);
			has_decimal = 1;
		}
		else if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (i > 0 && (i > 1 || (num[0] >= '0' && num[0] <= '9')));
}

double	ft_atof(char *num)
{
	double	result;
	double	fraction;
	int		sign;
	int		i;
	double	divisor;

	result = 0.0;
	fraction = 0.0;
	i = 0;
	sign = handle_sign(num, &i);
	while (num[i] >= '0' && num[i] <= '9')
		result = result * 10 + (num[i++] - '0');
	if (num[i] == '.')
	{
		i++;
		divisor = 10.0;
		while (num[i] >= '0' && num[i] <= '9')
		{
			fraction += (num[i] - '0') / divisor;
			divisor *= 10.0;
			i++;
		}
	}
	return ((result + fraction) * sign);
}
