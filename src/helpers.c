/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckappe <ckappe@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:38:10 by ckappe            #+#    #+#             */
/*   Updated: 2025/04/02 17:15:37 by ckappe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
	// mlw_destroy_image(fractol);
	// mlx_destroy_window(fractol);
	exit(EXIT_SUCCESS);
}
