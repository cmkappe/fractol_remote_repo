/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:38:10 by ckappe            #+#    #+#             */
/*   Updated: 2025/04/04 17:58:32 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"



int	ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i])
	{
		if (str1[i] != str2[i])
			return (ft_abs(str2[i] - str1[i]));
		i++;
	}
	return (0);
}

int	close_window(t_fractol *fractol)
{
	(void)fractol;
	// mlw_destroy_image(fractol);
	// mlx_destroy_window(fractol);
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
