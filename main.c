/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vminisa- <vminisa-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:36:41 by vminisa-          #+#    #+#             */
/*   Updated: 2019/09/18 19:45:15 by vminisa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define HEIGHT 100;
#define WIDTH 100;

#include "fractol.h"

int		close_hook(int button, void *mlx)
{
	(void)button;
	(void)mlx;
	exit(0);
	return (0);
}

void	user_interface_texts(void *mlx,void *win)
{
	mlx_string_put(mlx, win, 41, 35, UI_COLOR, "Controls Keys");
	mlx_string_put(mlx, win, 37, 63, UI_COLOR, "Move = ^ v < >");
	mlx_string_put(mlx, win, 37, 83, UI_COLOR, "Iter = W and Q");
	mlx_string_put(mlx, win, 37, 103, UI_COLOR, "Zoom = - and +");
	mlx_string_put(mlx, win, 37, 123, UI_COLOR, "Rot8 = R and T");
	mlx_string_put(mlx, win, 37, 143, UI_COLOR, "Mouse = M or S");
	mlx_string_put(mlx, win, 37, 163, UI_COLOR, "Color = SHIFT");
	mlx_string_put(mlx, win, 37, 183, UI_COLOR, "Reset = CLEAR");
	mlx_string_put(mlx, win, 37, 248, 1, "Controls Mouse");
	mlx_string_put(mlx, win, 37, 276, 1, "Zoom = SCROLL");
	mlx_string_put(mlx, win, 37, 296, 1, "or LMB and RMB");
	mlx_string_put(mlx, win, 37, (WIN_HEIGHT - 123), UI_COLOR, "Fract Explorer");
	mlx_string_put(mlx, win, 37, (WIN_HEIGHT - 95), UI_COLOR, "1 = Julia");
	mlx_string_put(mlx, win, 37, (WIN_HEIGHT - 75), UI_COLOR, "2 = Mandelbrot");
	mlx_string_put(mlx, win, 37, (WIN_HEIGHT - 55), UI_COLOR, "3 = Tricorn");
	mlx_string_put(mlx, win, 37, (WIN_HEIGHT - 55), UI_COLOR, "PROGRAM1");
}

int check_fractal(t_main *info,char *mb_fractal_name)
{
    if (!ft_strcmp(mb_fractal_name,"Julia") ||
        ft_strcmp(mb_fractal_name,"julia"))
    {
            info->fractal_code = 0;
            return 0;
    }
    else if (!ft_strcmp(mb_fractal_name,"Mandelbrot") ||
        ft_strcmp(mb_fractal_name,"mandelbrot"))
    {
            info->fractal_code = 1;
            return 0;
    }
    else if (!ft_strcmp(mb_fractal_name,"Tricorn") ||
        ft_strcmp(mb_fractal_name,"tricorn"))
    {
            info->fractal_code = 2;
            return 0;
    }
    else
        return 1;
}


void    *draw_fract(t_main *info)
{
    while(info->y < WIN_HEIGHT)
    {
        info->c_im = info->max_im - info->y * info->factor_im;
        info->x = 0;
        while(info->x < WIN_WIDTH)
        {
            info->c_re = info->min_re + info->x * info->factor_re;
            info->z_re = info->c_re;
            info->z_im = info->c_im;
            int iteration = 0;
            while ((pow(info->z_re,2.0) + pow(info->z_im,2.0)) <= 4
                && iteration < 50)
            {
                info->z_re = pow(info->z_re,2.0) - pow(info->z_im,2.0) + info->c_re;
                info->z_im = 2.0 * info->z_re * info->z_im + info->c_im;
                iteration++;
            }
            int t = (double)iteration / (double)50;

            int red = (int)(9 * (1 - t) * pow(t, 3) * 255);
            int green = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
            int blue = (int)(8.5 * pow((1 - t), 3) * t * 255);
                        /*if (info->fractal_code == 0)
                count_julia(info);
            else if (info->fractal_code == 1)
                count_mandel(info);
            else
                count_celtic(info);*/
            put_px_img(info->mlx, info->win, info->x,info->y,red * 255 * 255 + green * 255 + blue);
            info->x++;
        }
        info->y++;
    }

}

int main(int argc,char **argv) {
    if (argc != 2)
        ft_putstr("usage: ./fractol (Julia / Mandelbrot / Tricorn)");

    t_main *info = malloc(sizeof(t_main));
    info->mlx = mlx_init();
    info->win = mlx_new_window(info->mlx, WIN_WIDTH, WIN_HEIGHT, "Fractol");

    mlx_hook(info->win,17,0, close_hook, info->mlx);
    user_interface_texts(info->mlx,info->win);



    

    info->min_im = -2;
    info->min_re = -2;
    info->max_re = 2.0;
    info->max_im = info->min_im + (info->max_re - info->min_re) * WIN_HEIGHT / WIN_WIDTH;

    info->factor_re = (info->max_re - info->min_re) / (WIN_WIDTH - 1);
    info->factor_im = (info->max_im - info->min_im) / (WIN_HEIGHT - 1);

    int max_iteration = 50;
    mlx_loop(info->mlx);
    draw_fract(info);

    mlx_loop(info->mlx);

    
    //mlx_expose_hook(mlx,);
    
    return 0;
}


/*
{
    double min_re = -2.0;
    double max_re = 2.0;
    double min_im = -2.0;
    double max_im = min_im + (max_re - min_re) / ()
}
*/