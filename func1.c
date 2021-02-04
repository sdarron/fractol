/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 21:22:50 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/15 23:10:11 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_select(char *select)
{
	ft_putstr(select);
	return (0);
}

void	validfract(char *av[1], t_mand *m, t_julia *j, t_tree *t)
{
	if (ft_strcmp(av[1], m->nm) == 0)
		ft_mandel(m);
	if (ft_strcmp(av[1], j->nj) == 0)
		ft_julia(j);
	if (ft_strcmp(av[1], t->nt) == 0)
		ft_tree(t);
}

void	formdrag(double *pixx1, double y, double y1, t_drag *drag)
{
	double	x;
	double	x1;

	x = pixx1[0];
	x1 = pixx1[1];
	drag->xc = (x + x1) / 2 + (y1 - y) / 2;
	drag->yc = (y + y1) / 2 - (x1 - x) / 2;
}
