/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:54:04 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/16 18:36:24 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			j_deal_key(int key, t_julia *julia)
{
	if (key == 53)
		exit(0);
	if (key == 124)
		julia->crawlx -= 20;
	if (key == 123)
		julia->crawlx += 20;
	if (key == 126)
		julia->crawly -= 20;
	if (key == 125)
		julia->crawly += 20;
	if (key == 8)
		julia->colorgor += 0x10f0;
	if (key == 9 && julia->colorgor > 0x000000)
		julia->colorgor -= 0x10f0;
	mlx_clear_window(julia->mlx_ptr, julia->win_ptr);
	drawjulia(julia);
	j_presskey(julia);
	return (0);
}

int			j_mouse_release(int button, int x, int y, t_julia *julia)
{
	if (button == 4)
	{
		julia->scale *= 1.1;
		julia->crawlx -= 20;
	}
	if (button == 5)
	{
		julia->scale /= 1.1;
		julia->crawlx += 20;
	}
	if (x == 1)
		julia->mousx += 0.1;
	if (y == 1)
		julia->mousy += 0.1;
	if (button == 1)
		julia->colorstep -= 0x15;
	if (button == 2)
		julia->colorstep += 0x15;
	mlx_clear_window(julia->mlx_ptr, julia->win_ptr);
	drawjulia(julia);
	j_presskey(julia);
	return (0);
}

int			hook_mousemove(int x, int y, t_julia *julia)
{
	julia->mousx = x;
	julia->mousy = y;
	mlx_clear_window(julia->mlx_ptr, julia->win_ptr);
	drawjulia(julia);
	j_presskey(julia);
	return (0);
}

void		juliapix(int l, int i, t_julia *j)
{
	int		k;
	int		col;
	int		m;

	k = 0;
	while (k < 300 && j->zr * j->zr + j->zi * j->zi < 4)
	{
		j->tmp = j->zr;
		j->zr = j->zr * j->zr - j->zi * j->zi + 0.1 + j->mousx / 600;
		j->zi = 2 * j->tmp * j->zi + 0.1 + j->mousy / 600;
		k++;
		j->color += j->colorstep;
	}
	if (k < 300)
	{
		col = j->color + j->colorgor;
		m = l + 650 - j->crawlx;
		mlx_pixel_put(j->mlx_ptr, j->win_ptr, m, i + 650 + j->crawly, col);
	}
}

void		drawjulia(t_julia *j)
{
	int		i;
	int		l;
	int		n;

	i = -650 - j->crawly;
	n = 1;
	while (i < 650 - j->crawly)
	{
		l = -650 + j->crawlx;
		while (l < 650 + j->crawlx)
		{
			j->zi = ((double)i) / j->scale;
			j->zr = ((double)l) / j->scale;
			j->color = 0x0000FF;
			juliapix(l, i, j);
			l++;
		}
		i++;
	}
}
