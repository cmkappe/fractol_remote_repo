/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:34:38 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/25 18:44:21 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	get_colour(int iter, t_fractol *fractol)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == MAX_ITER)
		return (COLOUR_BLACK);
	t = (double)iter / fractol->max_iterations;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	r %= 256;
	g %= 256;
	b %= 256;
	return (r << 16 | g << 8 | b);
}

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

double	normalizing(double un_number, double new_min, double new_max,
	double old_max)
{
	return ((((new_max - new_min) * un_number) / old_max) + new_min);
}