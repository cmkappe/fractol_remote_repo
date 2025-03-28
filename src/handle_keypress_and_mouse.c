/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_and_mouse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:24:04 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/28 18:25:01 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int mouse_hook(int button, int x, int y, t_fractol *fractol)
{
    if (button == SCROLL_UP) // Zoom in
        zoom(fractol, x, y, 1.2);
    else if (button == SCROLL_DOWN) // Zoom out
        zoom(fractol, x, y, 0.8);

    render(fractol); // Redraw the fractal after zooming
    return (0);
}

int	handle_keypresses(int keycode, int x, int y, t_fractol *fractol)
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
	else if (keycode == KEY_PLUS)
		zoom(fractol, x, y, 1.2);
	else if (keycode == KEY_MINUS)
		zoom(fractol, x, y, 0.8);
	render(fractol);
	return (0);
}
