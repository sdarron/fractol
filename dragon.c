/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 20:38:19 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/16 18:47:47 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			d_deal_key(int key, t_drag *drag)
{
	double	xyx1y1[4];
	int		n;

	d_deal_key1(key, drag);
	if (key == 8)
		drag->colorgor += 0x1f0;
	if (key == 9 && drag->colorgor >= 0x000000)
		drag->colorgor -= 0x1f0;
	mlx_clear_window(drag->mlx_ptr, drag->win_ptr);
	xyx1y1[0] = 700.0 + drag->crawlx;
	xyx1y1[1] = 300.0 + drag->crawly;
	xyx1y1[2] = 400.0 + drag->scale + drag->crawlx;
	xyx1y1[3] = 800.0 + drag->scale + drag->crawly;
	n = 30 + drag->n;
	drag->color = 0x000000;
	drdr(xyx1y1, n, drag);
	d_presskey(drag);
	return (0);
}

int			d_mouse_release(int button, int x, int y, t_drag *drag)
{
	double	xyx1y1[4];
	int		n;

	x = 0;
	y = 0;
	if (button == 4)
	{
		drag->scale = 5 + drag->scale * 1.07;
		drag->n += 0.1;
	}
	if (button == 5)
		if (drag->scale > 20.0)
			drag->scale /= 1.1;
	mlx_clear_window(drag->mlx_ptr, drag->win_ptr);
	xyx1y1[0] = 700.0 + drag->crawlx;
	xyx1y1[1] = 300.0 + drag->crawly;
	xyx1y1[2] = 400.0 + drag->scale + drag->crawlx;
	xyx1y1[3] = 800.0 + drag->scale + drag->crawly;
	n = 30 + drag->n;
	drag->color = 0x000000;
	drdr(xyx1y1, n, drag);
	d_presskey(drag);
	return (0);
}

void		dpixel(double xx1[2], double y, double y1, t_drag *d)
{
	double	stepx;
	double	stepy;
	double	x;
	double	x1;

	x = xx1[0];
	x1 = xx1[1];
	stepx = (x1 - x) / maxim(mod(x1 - x), mod(y1 - y));
	stepy = (y1 - y) / maxim(mod(x1 - x), mod(y1 - y));
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(d->mlx_ptr, d->win_ptr, x, y, d->color + d->colorgor);
		x = x + stepx;
		y = y + stepy;
	}
}

double		*coord(double x, double y, double x1, double y1)
{
	double	*xyx1y1;

	xyx1y1 = (double*)ft_memalloc(sizeof(double) * 4);
	xyx1y1[0] = x;
	xyx1y1[1] = y;
	xyx1y1[2] = x1;
	xyx1y1[3] = y1;
	return (xyx1y1);
}

void		drdr(double *xyx1y1, int n, t_drag *drag)
{
	double	pixx1[2];
	double	x;
	double	y;
	double	x1;
	double	y1;

	x = xyx1y1[0];
	y = xyx1y1[1];
	x1 = xyx1y1[2];
	y1 = xyx1y1[3];
	if (n-- > 0)
	{
		pixx1[0] = x;
		pixx1[1] = x1;
		dpixel(pixx1, y, y1, drag);
		drag->color = drag->color + 0x2;
		formdrag(pixx1, y, y1, drag);
		xyx1y1 = coord(x, y, drag->xc, drag->yc);
		drdr(xyx1y1, n - 1, drag);
		ft_memdel((void**)&xyx1y1);
		formdrag(pixx1, y, y1, drag);
		xyx1y1 = coord(x1, y1, drag->xc, drag->yc);
		drdr(xyx1y1, n - 1, drag);
		ft_memdel((void**)&xyx1y1);
	}
}
