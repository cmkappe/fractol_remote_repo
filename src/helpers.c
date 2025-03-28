/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:38:10 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/27 18:03:22 by chiarakappe      ###   ########.fr       */
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

int	close_window(t_fractol *fractol)
{
	(void)fractol;
	// mlw_destroy_image
	// mlx_destroy_window
	exit(EXIT_SUCCESS);
}

int	handle_keypresses(int keycode, t_fractol *fractol)
{
	if (keycode == ESC_KEY)
		close_window(fractol);
	else if (keycode == KEY_LEFT)
		fractol->offset_x += 0.2;
	else if (keycode == KEY_RIGHT)
		fractol->offset_x -= 0.2;
	else if (keycode == KEY_UP)
		fractol->offset_y += 0.2;
	else if (keycode == KEY_DOWN)
		fractol->offset_y -= 0.2;
	render(fractol);
	return (0);
}
