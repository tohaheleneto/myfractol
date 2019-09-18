/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminisa- <vminisa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:37:42 by vminisa-          #+#    #+#             */
/*   Updated: 2019/09/18 19:44:44 by vminisa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#define WIN_WIDTH 1028
#define WIN_HEIGHT 720
#define UI_COLOR 0xC0C0C0
# include <math.h>
# include <stdlib.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"

typedef struct	s_main
{
    char fractal_code;
    int			x;
	int			y;
    double      z_re;
    double      z_im;
    double      min_re;
    double      min_im;
    double      max_re;
    double      max_im;
    void		*mlx;
    void		*win;
    double      factor_re;
    double      factor_im;
    double      c_re;
    double      c_im;
    void	    *img;

}   t_main;


#endif