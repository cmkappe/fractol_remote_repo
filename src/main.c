/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:50:57 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/04/04 20:17:14 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->adress_pointer + (y * data->len_of_line
			+ x * (data->bits_per_pxl / 8));
	*(unsigned int *)dst = colour;
}

static void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_pointer = mlx_init();
	fractol->max_iterations = MAX_ITER;
	fractol->window_pointer = mlx_new_window(fractol->mlx_pointer,
			WIDTH, HEIGHT, fractol->title);
	fractol->img.img_pointer = mlx_new_image(fractol->mlx_pointer,
			WIDTH, HEIGHT);
	fractol->img.adress_pointer = mlx_get_data_addr(fractol->img.img_pointer,
			&fractol->img.bits_per_pxl, &fractol->img.len_of_line,
			&fractol->img.endian);
	fractol->zoom = 1;
	fractol->offset_x = 0;
	fractol->offset_x = 0;
	fractol->julia_real = 0;
	fractol->julia_imag = 0;
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (!((ac == 2 && !ft_strcmp(av[1], "Mandelbrot"))
 		|| (ac == 4 && !ft_strcmp(av[1], "Julia"))
		|| (ac == 2 && !ft_strcmp(av[1], "Burning_ship"))))
	{
		write(1, "Wrong input, pls try one of the following parameters:\n", 55);
		write(1, "Mandelbrot\nJulia -.79 .15 // .28 .008\nBurning_ship\n", 52);
		exit(EXIT_SUCCESS);
	}
	fractol_init(&fractol);
	fractol.title = av[1];
	if (!ft_strcmp(av[1], "Julia"))
	{
		fractol.julia_real = ft_atof(av[2]);
		fractol.julia_imag = ft_atof(av[3]);
	}
	mlx_hook(fractol.window_pointer, 2, 1L << 0, handle_keypresses, &fractol);
	mlx_hook(fractol.window_pointer, 17, 1L << 17, close_window, &fractol);
	mlx_mouse_hook(fractol.window_pointer, mouse_hook, &fractol);
	render(&fractol);
	mlx_loop(fractol.mlx_pointer);
	exit(EXIT_SUCCESS);
}
