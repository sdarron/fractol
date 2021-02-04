/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 00:01:02 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/15 22:31:46 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	maxim(double a, double b)
{
	return (a > b) ? a : b;
}

double	mod(double i)
{
	return (i < 0) ? -i : i;
}

void	d_deal_key1(int key, t_drag *drag)
{
	if (key == 53)
		exit(0);
	if (key == 123)
		drag->crawlx -= 20;
	if (key == 124)
		drag->crawlx += 20;
	if (key == 126)
		drag->crawly -= 20;
	if (key == 125)
		drag->crawly += 20;
}

void	name(t_mand *mandel, t_julia *julia, t_tree *tree, t_drag *drag)
{
	mandel->nm = "Mandelbrot";
	julia->nj = "Julia";
	tree->nt = "Tree";
	drag->nd = "Dragon";
}

int		frafree(t_mand *m, t_julia *j, t_tree *t, t_drag *d)
{
	ft_memdel((void**)&t);
	ft_memdel((void**)&j);
	ft_memdel((void**)&m);
	ft_memdel((void**)&d);
	return (0);
}
