/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:17:51 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/04/06 17:37:51 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx/mlx.h"

# define MAX_ITER 80
# define HEIGHT 800
# define WIDTH 800

# define ESC_KEY 53
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_PLUS 69
# define KEY_MINUS 78
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define KEY_C 8

# define COLOUR_BLACK 0x000000

typedef struct s_double_data
{
	double	real;
	double	imag;
}				t_double_data;

typedef struct s_img
{
	void	*img_pointer;
	char	*adress_pointer;
	int		bits_per_pxl;
	int		len_of_line;
	int		endian;
}				t_img;

typedef struct s_fractol
{
	void	*mlx_pointer;
	void	*window_pointer;
	char	*title;
	int		max_iterations;
	double	julia_real;
	double	julia_imag;
	double	offset_x;
	double	offset_y;
	double	zoom;

	t_img	img;
}				t_fractol;


void			my_mlx_pixel_put(t_img *data, int x, int y, int colour);

double			ft_abs(double n);
int				ft_strcmp(char *str1, char *str2);
int				close_window(t_fractol *fractol);
double			ft_atof(char *num);
int				julia_in(char *num);

int				mouse_hook(int button, int x, int y, t_fractol *fractol);
int				handle_keypresses(int keycode, t_fractol *fractol);
//int				key_hook(int keycode, t_fractol *fractol);

t_double_data	fractol_sum(t_double_data z1, t_double_data z2);
t_double_data	fractol_sqr(t_double_data z);
double			normal(double un_number, double new_min, double new_max,
					double old_max);

int				get_colour(int iter, t_fractol *fractol);
int				render(t_fractol *fractol);

#endif