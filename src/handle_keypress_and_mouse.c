/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_and_mouse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:24:04 by ckappe            #+#    #+#             */
/*   Updated: 2025/04/02 17:20:01 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (keycode == SCROLL_UP)
		fractol->zoom *= 1.1;
    else if (keycode == SCROLL_DOWN)
		fractol->zoom *= 0.9;
	render(fractol);
	return (0);
}

int	handle_keypresses(int keycode, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (keycode == ESC_KEY)
		close_window(fractol);
	else if (keycode == KEY_LEFT)
		fractol->offset_x += 0.01;
	else if (keycode == KEY_RIGHT)
		fractol->offset_x -= 0.01;
	else if (keycode == KEY_UP)
		fractol->offset_y += 0.01;
	else if (keycode == KEY_DOWN)
		fractol->offset_y -= 0.01;
	render(fractol);
	return (0);
}
