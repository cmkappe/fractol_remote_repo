/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_fractol.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 15:28:31 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/04/02 17:50:09 by ckappe           ###   ########.fr       */
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
	r = (int)(252 * (1 - t) * t * 4);
	g = (int)(190 * (1 - t) * (1 - t) * t * 6);
	b = (int)(17 + 50 * (10 * t));
	r %= 256;
	g %= 256;
	b %= 256;
	return (r << 16 | g << 8 | b);
}

static	t_double_data	pick_fractol(t_fractol *fractol, t_double_data z_imag)
{
	t_double_data	c_const;

	if (ft_strcmp(fractol->title, "Julia") == 0)
	{
		c_const.real = fractol->julia_real;
		c_const.imag = fractol->julia_imag;
	}
	else
	{
		c_const = z_imag;
		z_imag.real = 0;
		z_imag.imag = 0;
	}
	return (c_const);
}

static t_double_data	burning(t_fractol *fractol, t_double_data z_imag)
{
	if (ft_strcmp(fractol->title, "Burning ship") == 0)
	{
		z_imag.real = ft_abs(z_imag.real);
		z_imag.imag = ft_abs(z_imag.imag);
	}
	return (z_imag);
}

static int	iterations(int x, int y, t_fractol *fractol)
{
	int				colour;
	t_double_data	z_imag;
	t_double_data	c_const;
	int				iterations;

	z_imag.real = normal(x, -2, 2, WIDTH) / fractol->zoom + fractol->offset_x;
	z_imag.imag = normal(y, -2, 2, HEIGHT) / fractol->zoom + fractol->offset_y;
	c_const = pick_fractol(fractol, z_imag);
	iterations = 0;
	while (iterations <= fractol->max_iterations)
	{
		z_imag = burning(fractol, z_imag);
		z_imag = fractol_sum(fractol_sqr(z_imag), c_const);
		if ((z_imag.real * z_imag.real + z_imag.imag * z_imag.imag) > 4)
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
	mlx_put_image_to_window(fractol->mlx_pointer, fractol->window_pointer,
		fractol->img.img_pointer, 0, 0);
	return (0);
}
