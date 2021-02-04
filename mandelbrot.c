/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 01:48:26 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/16 21:15:38 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <pthread.h>

int		m_deal_key(int key, t_mand *mandel)
{
	if (key == 53)
		exit(0);
	if (key == 124)
		mandel->x -= 20;
	if (key == 123)
		mandel->x += 20;
	if (key == 126)
		mandel->y -= 20;
	if (key == 125)
		mandel->y += 20;
	if (key == 8)
		mandel->colorgor += 0x3f0;
	if (key == 9)
		mandel->colorgor -= 0x3f0;
	mlx_clear_window(mandel->mlx_ptr, mandel->win_ptr);
	drawmandel(mandel);
	m_presskey(mandel);
	return (0);
}

int		mouse_release(int button, int x, int y, t_mand *mandel)
{
	x = 0;
	y = 0;
	if (button == 4)
	{
		mandel->scale *= 1.1;
		mandel->x -= 20;
	}
	if (button == 5)
	{
		mandel->scale /= 1.1;
		mandel->x += 20;
	}
	if (button == 1)
		mandel->colorstep -= 0x15;
	if (button == 2)
		mandel->colorstep += 0x15;
	mlx_clear_window(mandel->mlx_ptr, mandel->win_ptr);
	drawmandel(mandel);
	m_presskey(mandel);
	return (0);
}

int		cinumb(t_mand *mandel)
{
	int	k;

	k = 0;
	while (k < 300)
	{
		mandel->tmp = mandel->zr * mandel->zr - mandel->zi * mandel->zi;
		mandel->zi = 2 * mandel->zr * mandel->zi + mandel->ci;
		mandel->zr = mandel->tmp + mandel->cr;
		if (mandel->zr * mandel->zr + mandel->zi * mandel->zi > 4)
			break ;
		k++;
		mandel->c += mandel->colorstep;
	}
	return (k);
}

void	pixmand(int j, int i, t_mand *m)
{
	m->c = m->c + m->colorgor;
	mlx_pixel_put(m->mlx_ptr, m->win_ptr, j + 900 - m->x, i + 600 + m->y, m->c);
}

void	drawmandel(t_mand *m)
{
	int	i;
	int	j;
	int	n;

	i = -600 - m->y;
	n = 1;
	while (i < 700 - m->y)
	{
		m->ci = ((double)i) / m->scale;
		j = -900 + m->x;
		while (j < 400 + m->x)
		{
			m->cr = ((double)j) / m->scale;
			m->zi = 0.0;
			m->zr = 0.0;
			m->c = 0x800070;
			if (cinumb(m) < 300)
				pixmand(j, i, m);
			j++;
		}
		i++;
	}
}
