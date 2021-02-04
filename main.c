/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:40:57 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/16 21:07:22 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			ft_mandel(t_mand *ml)
{
	ml->mlx_ptr = mlx_init();
	ml->win_ptr = mlx_new_window(ml->mlx_ptr, 1300, 1300, "Fractal Mandelbrot");
	mlx_key_hook(ml->win_ptr, m_deal_key, ml);
	mlx_mouse_hook(ml->win_ptr, mouse_release, ml);
	ml->scale = 400.0;
	ml->x = 0;
	ml->y = 0;
	ml->colorgor = 0;
	ml->colorstep = 0x15;
	drawmandel(ml);
	m_presskey(ml);
	mlx_loop(ml->mlx_ptr);
	ft_memdel((void**)&ml);
}

void			ft_julia(t_julia *j)
{
	j->mlx_ptr = mlx_init();
	j->win_ptr = mlx_new_window(j->mlx_ptr, 1300, 1300, "Fractal Julia");
	mlx_key_hook(j->win_ptr, j_deal_key, j);
	mlx_mouse_hook(j->win_ptr, j_mouse_release, j);
	mlx_hook(j->win_ptr, 6, 0, hook_mousemove, j);
	j->scale = 400.0;
	j->mousx = 0.0;
	j->mousy = 0.0;
	j->crawlx = 0.0;
	j->crawly = 0.0;
	j->colorgor = 0;
	j->colorstep = 0x30;
	drawjulia(j);
	j_presskey(j);
	mlx_loop(j->mlx_ptr);
	ft_memdel((void**)&j);
}

void			ft_tree(t_tree *tree)
{
	double	p;
	double	xy[2];

	p = 3.14159;
	tree->mlx_ptr = mlx_init();
	tree->win_ptr = mlx_new_window(tree->mlx_ptr, 1300, 1300, "Fractal Tree");
	tree->scale = 300.0;
	mlx_key_hook(tree->win_ptr, t_deal_key, tree);
	mlx_mouse_hook(tree->win_ptr, tr_mouse_release, tree);
	mlx_hook(tree->win_ptr, 6, 0, t_hook_mousemove, tree);
	tree->crawly = 0;
	tree->crawlx = 0;
	tree->colorgor = 0;
	tree->windl = 0.0;
	tree->windr = 0.0;
	tree->color = 0x006400;
	xy[0] = 620.0;
	xy[1] = 960.0;
	drawtree(xy, tree->scale, p / 2, tree);
	t_presskey(tree);
	mlx_loop(tree->mlx_ptr);
	ft_memdel((void**)&tree);
}

void			ft_dragon(t_drag *drag)
{
	int			n;
	double		xyx1y1[4];

	drag->mlx_ptr = mlx_init();
	drag->win_ptr = mlx_new_window(drag->mlx_ptr, 1300, 1300, "Fractal Dragon");
	drag->color = 0x000000;
	drag->scale = 0.0;
	drag->crawlx = 0.0;
	drag->crawly = 0.0;
	drag->colorgor = 0;
	drag->n = 0;
	xyx1y1[0] = 700.0;
	xyx1y1[1] = 300.0;
	xyx1y1[2] = 400.0;
	xyx1y1[3] = 800.0;
	n = 30 + drag->n;
	mlx_key_hook(drag->win_ptr, d_deal_key, drag);
	mlx_mouse_hook(drag->win_ptr, d_mouse_release, drag);
	drdr(xyx1y1, n, drag);
	d_presskey(drag);
	mlx_loop(drag->mlx_ptr);
	ft_memdel((void**)&xyx1y1);
	ft_memdel((void**)&drag);
}

int				main(int argc, char *av[])
{
	char		*select;
	t_mand		*m;
	t_julia		*j;
	t_tree		*t;
	t_drag		*d;

	select = "Select one fractal: Mandelbrot, Julia, Tree or Dragon\n";
	if (!(m = (t_mand*)ft_memalloc(sizeof(t_mand))))
		return (0);
	if (!(j = (t_julia*)ft_memalloc(sizeof(t_julia))))
		return (0);
	if (!(t = (t_tree*)ft_memalloc(sizeof(t_tree))))
		return (0);
	if (!(d = (t_drag*)ft_memalloc(sizeof(t_drag))))
		return (0);
	name(m, j, t, d);
	if (argc != 2)
		return (ft_select(select));
	validfract(av, m, j, t);
	if (ft_strcmp(av[1], d->nd) == 0)
		ft_dragon(d);
	else
		ft_putstr(select);
	frafree(m, j, t, d);
}
