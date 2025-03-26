/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:38:10 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/25 18:50:38 by ckappe           ###   ########.fr       */
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


int	handle_keypress(int keycode, t_fractol *fractol)
{
	if (keycode == ESC_KEY)
		close_window(fractol);
	// if (keycode == arrow left/right/up/down)
	return (0);
}
