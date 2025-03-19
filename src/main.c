/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:50:57 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/03/19 15:08:00 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

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

void	my_mlx_pixel_put(t_img *data, int x, int y, int colour)
{
	char	*dst;

	dst = data->adress_pointer + (y * data->len_of_line +
			x * (data->bits_per_pxl / 8));
	*(unsigned int *)dst = colour;
}

static void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_pointer = mlx_init();
	fractol->max_iterations = 100;
	fractol->window_pointer = mlx_new_window(fractol->mlx_pointer,
			WIDTH, HEIGHT, fractol->title);
	fractol->img.img_pointer = mlx_new_image(fractol->mlx_pointer,
			WIDTH, HEIGHT);
	fractol->img.adress_pointer = mlx_get_data_addr(fractol->img.img_pointer,
			&fractol->img.bits_per_pxl, &fractol->img.len_of_line,
			&fractol->img.endian);
}

int	close_window(t_fractol *fractol)
{
	(void)fractol;
	exit(EXIT_SUCCESS);
}

int	handle_keypress(int keycode, t_fractol *fractol)
{
	if (keycode == ESC_KEY)
		close_window(fractol);
	return (0);
}

int main(int ac, char **av)
{
	t_fractol	fractol;

	if (!((ac == 2 && !ft_strcmp(av[1], "Mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "Julia"))))
	{
		printf("Wrong input, please try again.");
		exit(EXIT_FAILURE);
	}
	fractol.title = av[1];
	fractol_init(&fractol);

	mlx_hook(fractol.window_pointer, 2, 1L << 0, handle_keypress, &fractol);
	mlx_hook(fractol.window_pointer, 17, 1L << 17, close_window, &fractol);

	render(&fractol);

	mlx_loop(fractol.mlx_pointer);


	exit(EXIT_SUCCESS);
}