/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:28:31 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/22 17:53:04 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static int iterations(int x, int y, t_fractol *fractol)
{
	int	colour;
	t_double_data	z_imag;
	t_double_data	c_const;
	int				iterations;
	
	c_const.real = normalizing(x * WIDTH, -0.2, 0.2, WIDTH);
	c_const.imaginary = normalizing(y * HEIGHT, -0.2, 0.2, HEIGHT);
	z_imag.imaginary = 0;
	z_imag.real = 0;
	iterations = 0;

	while (iterations <= fractol->max_iterations)
	{
		z_imag = fractol_sum(fractol_sqr(z_imag), c_const);
		if ((z_imag.real * z_imag.real + z_imag.imaginary * z_imag.imaginary) > 4)
		{
			colour = get_colour(iterations, fractol);
			my_mlx_pixel_put(&fractol->image, x, y, colour);
			return (0);
		}
		iterations++;
	}
	my_mlx_pixel_put(&fractol->image, x, y, COLOUR_BLACK);
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
	mlx_put_image_to_window(fractol->mlx_pointer, fractol->window_pointer, fractol->image.image_pointer, x, y);
	return (0);
}