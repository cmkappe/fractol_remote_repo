/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_and_mouse.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:24:04 by ckappe            #+#    #+#             */
/*   Updated: 2025/03/28 19:37:15 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int mouse_hook(int keycode, int x, int y, t_fractol *fractol)
{

	(void)x;
	(void)y;
   // printf("Mouse event: button=%d, x=%d, y=%d\n", keycode, x, y);
	if (keycode == SCROLL_UP) // Zoom in
		fractol->zoom *= 1.2;
     //   zoom(fractol, x, y, 1.2);
	
    else if (keycode == SCROLL_DOWN) // Zoom out
		fractol->zoom *= 0.8;
	//    zoom(fractol, x, y, 0.8);
		
    render(fractol); // Redraw the fractal after zooming
    return (0);
}

// int key_hook(int keycode, t_fractol *fractol)
// {
//     if (keycode == KEY_PLUS) // Zoom in
//     {
//         zoom(fractol, WIDTH / 2, HEIGHT / 2, 1.2); // Zoom at the center
//     }
//     else if (keycode == KEY_MINUS) // Zoom out
//     {
//         zoom(fractol, WIDTH / 2, HEIGHT / 2, 0.8); // Zoom at the center
//     }

//     render(fractol); // Redraw the fractal after zooming
//     return (0);
// }

int	handle_keypresses(int keycode, int x, int y, t_fractol *fractol)
{

	(void)x;
	(void)y;
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
	// else if (keycode == KEY_PLUS)
	// 	zoom(fractol, x, y, 1.2);
	// else if (keycode == KEY_MINUS)
	// 	zoom(fractol, x, y, 0.8);
	render(fractol);
	return (0);
}
