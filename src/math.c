/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:34:38 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/04/05 21:22:16 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_abs(double n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

t_double_data	fractol_sum(t_double_data z1, t_double_data z2)
{
	t_double_data	sum;

	sum.real = z1.real + z2.real;
	sum.imag = z1.imag + z2.imag;
	return (sum);
}

// (a + bi)^2 = a² - b² + 2abi

t_double_data	fractol_sqr(t_double_data z)
{
	t_double_data	res;

	res.real = (z.real * z.real) - (z.imag * z.imag);
	res.imag = 2 * z.real * z.imag;
	return (res);
}

double	normal(double un_number, double new_min, double new_max,
	double old_max)
{
	return ((((new_max - new_min) * un_number) / old_max) + new_min);
}
