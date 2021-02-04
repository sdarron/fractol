/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 22:26:24 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/16 18:52:33 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			t_deal_key(int key, t_tree *t)
{
	double	p;
	double	xy[2];

	p = 3.14159;
	if (key == 53)
		exit(0);
	if (key == 123)
		t->crawlx -= 20;
	if (key == 124)
		t->crawlx += 20;
	if (key == 126)
		t->crawly -= 20;
	if (key == 125)
		t->crawly += 20;
	if (key == 8)
		t->colorgor += 0x10f0;
	if (key == 9 && t->colorgor > 0x000000)
		t->colorgor -= 0x10f0;
	mlx_clear_window(t->mlx_ptr, t->win_ptr);
	xy[0] = 620.0 + t->crawlx;
	xy[1] = 960.0 + t->crawly;
	drawtree(xy, t->scale, p / 2, t);
	t_presskey(t);
	return (0);
}

int			t_hook_mousemove(int x, int y, t_tree *tree)
{
	double	xy[2];
	double	p;

	y = 0;
	p = 3.14159;
	xy[0] = 620.0 + tree->crawlx;
	xy[1] = 960.0 + tree->crawly;
	if (x > 620 && tree->windr < 0.33)
	{
		tree->windr = tree->windr + (double)x / 400000;
		tree->windl = 0;
	}
	if (x <= 620 && tree->windl < 0.4)
	{
		tree->windl = tree->windl + (double)x / 250000;
		tree->windr = 0;
	}
	mlx_clear_window(tree->mlx_ptr, tree->win_ptr);
	drawtree(xy, tree->scale, p / 2, tree);
	t_presskey(tree);
	return (0);
}

int			tr_mouse_release(int button, int x, int y, t_tree *tree)
{
	double p;
	double xy[2];

	x = 0;
	y = 0;
	p = 3.14159;
	if (button == 4)
	{
		tree->scale *= 1.05;
		tree->crawly += 15.0;
	}
	if (button == 5)
	{
		tree->scale /= 1.05;
		tree->crawly -= 15.0;
	}
	mlx_clear_window(tree->mlx_ptr, tree->win_ptr);
	xy[0] = 620.0;
	xy[1] = 960.0 + tree->crawly;
	drawtree(xy, tree->scale, p / 2, tree);
	t_presskey(tree);
	return (0);
}

void		pixel(double xx1[2], double y, double y1, t_tree *t)
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
		mlx_pixel_put(t->mlx_ptr, t->win_ptr, x, y, t->color + t->colorgor);
		x = x + stepx;
		y = y + stepy;
	}
}

void		drawtree(double xy[2], double l, double a, t_tree *tree)
{
	double	xx1[2];
	double	x;
	double	y;

	x = xy[0];
	y = xy[1];
	if (l > 1.0)
	{
		l *= 0.7;
		xx1[0] = x;
		xx1[1] = x + l * cos(a);
		pixel(xx1, y, y - l * sin(a), tree);
		x = x + l * cos(a);
		y = y - l * sin(a);
		tree->color = tree->color + 0x2;
		if (tree->color > 0x006450)
			tree->color = 0x006400;
		xy[0] = x;
		xy[1] = y;
		drawtree(xy, l, a - 0.25 - tree->windr + 3.14159 / 4, tree);
		xy[0] = x;
		xy[1] = y;
		drawtree(xy, l, a + tree->windl - 3.14159 / 4, tree);
	}
}
