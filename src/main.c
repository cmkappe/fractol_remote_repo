/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 11:50:57 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/22 12:48:33 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int ft_strcmp(char *str1, char *str2)
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



int main(int ac, char **av)
{
	t_fractol	fractol;
	
	if (!((ac == 2 && !ft_strcmp(av[1], "Mandelbrot")) 
		|| (ac == 4 && !ft_strcmp(av[1], "Julia"))))
	{
		printf("Wrong input, please try again.");
		exit(EXIT_FAILURE);
	}
	fractol.mlx_pointer = mlx_init();
	fractol.title = av[1];
	fractol.window_pointer = mlx_new_window(fractol.mlx_pointer, WIDTH, HEIGHT, fractol.title);
	fractol.image.image_pointer = mlx_new_image(fractol.mlx_pointer, WIDTH, HEIGHT);
	fractol.image.adress_pointer = mlx_get_data_addr(fractol.image.image_pointer, 
		&fractol.image.bits_per_pxl, &fractol.image.len_of_line, &fractol.image.endian);

	exit(EXIT_SUCCESS);
}