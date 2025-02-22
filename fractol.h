/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:17:51 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/22 14:32:36 by chiarakappe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "./mlx/mlx.h"

# define HEIGHT 800
# define WIDTH 800

# define ESC_KEY 53
# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define MOUSE_WHEEL_UP 2
# define MOUSE_WHEEL_DOWN 1
# define KEY_C 8


typedef struct s_image
{
	void	*image_pointer;
	char	*adress_pointer;
	int		bits_per_pxl;
	int		len_of_line;
	int		endian;
	
}				t_image;

typedef struct s_fractol
{
	void	*mlx_pointer;
	void	*window_pointer;
	char	*title;
	t_image	image;
}				t_fractol;

int		ft_abs(int n);
int		ft_strcmp(char *str1, char *str2);
int		handle_keypress(int keycode, t_fractol *fractol);
int		close_window(t_fractol *fractol);
void	my_mlx_pixel_put(t_image *data, int x, int y, int colour);


#endif