/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chiarakappe <chiarakappe@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 12:17:51 by chiarakappe       #+#    #+#             */
/*   Updated: 2025/02/22 12:41:50 by chiarakappe      ###   ########.fr       */
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



int		ft_abs(int n);
int		ft_strcmp(char *str1, char *str2);


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




#endif