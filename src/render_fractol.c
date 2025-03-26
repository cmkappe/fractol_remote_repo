/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:28:31 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/25 18:45:22 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int iterations(int x, int y, t_fractol *fractol)
{
	int	colour;
	t_double_data	z_imag;
	t_double_data	c_const;
	int				iterations;

	z_imag.real = normalizing(x, -2, 2, WIDTH);
	z_imag.imaginary = normalizing(y, -2, 2, HEIGHT);
	if (ft_strcmp(fractol->title, "Mandelbrot") == 0)
	{
		c_const = z_imag;
		z_imag.real = 0;
		z_imag.imaginary = 0;
	}
	else
	{
		c_const.real = fractol->julia_real;
		c_const.imaginary = fractol->julia_imag;
	}
	iterations = 0;
	while (iterations <= fractol->max_iterations)
	{
		z_imag = fractol_sum(fractol_sqr(z_imag), c_const);
		if ((z_imag.real * z_imag.real + z_imag.imaginary * z_imag.imaginary) > 4)
		{
			colour = get_colour(iterations, fractol);
			my_mlx_pixel_put(&fractol->img, x, y, colour);
			return (0);
		}
		iterations++;
	}
	my_mlx_pixel_put(&fractol->img, x, y, COLOUR_BLACK);
	return (0);
}
int	render(t_fractol *fractol)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			iterations(x, y, fractol);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractol->mlx_pointer, fractol->window_pointer, fractol->img.img_pointer, 0, 0);
	return (0);
}
