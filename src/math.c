/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:34:38 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/28 18:19:07 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

t_double_data	fractol_sum(t_double_data z1, t_double_data z2)
{
	t_double_data	sum;

	sum.real = z1.real + z2.real;
	sum.imaginary = z1.imaginary + z2.imaginary;
	return (sum);
}

t_double_data	fractol_sqr(t_double_data z)
{
	t_double_data	res;

	res.real = (z.real * z.real) - (z.imaginary * z.imaginary); // (a + bi)^2 = a² - b² + 2abi
	res.imaginary = 2 * z.real * z.imaginary;
	return (res);
}

/* double	normalizing(int value, double min, double max, int size, t_fractol *fractol)
{
	return ((double)value / size) * (max - min) * fractol->zoom + min;
} */

double	normalizing(double un_number, double new_min, double new_max,
	double old_max)
{
	return ((((new_max - new_min) * un_number) / old_max) + new_min);
}