/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presskey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:28:25 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/16 16:34:49 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		m_presskey(t_mand *mandel)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "Leave:   esc";
	str2 = "Scale:   mouse scroll";
	str3 = "Translation:   ->   <-";
	str4 = "Color change:   C   V";
	mlx_string_put(mandel->mlx_ptr, mandel->win_ptr, 50, 50, 0xC0C0C0, str1);
	mlx_string_put(mandel->mlx_ptr, mandel->win_ptr, 50, 80, 0xC0C0C0, str2);
	mlx_string_put(mandel->mlx_ptr, mandel->win_ptr, 50, 110, 0xC0C0C0, str3);
	mlx_string_put(mandel->mlx_ptr, mandel->win_ptr, 50, 140, 0xC0C0C0, str4);
}

void		j_presskey(t_julia *julia)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "Leave:   esc";
	str2 = "Scale:   mouse scroll";
	str3 = "Translation:   ->   <-";
	str4 = "Color change:   C   V";
	mlx_string_put(julia->mlx_ptr, julia->win_ptr, 50, 50, 0xC0C0C0, str1);
	mlx_string_put(julia->mlx_ptr, julia->win_ptr, 50, 80, 0xC0C0C0, str2);
	mlx_string_put(julia->mlx_ptr, julia->win_ptr, 50, 110, 0xC0C0C0, str3);
	mlx_string_put(julia->mlx_ptr, julia->win_ptr, 50, 140, 0xC0C0C0, str4);
}

void		t_presskey(t_tree *tree)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "Leave:   esc";
	str2 = "Scale:   mouse scroll";
	str3 = "Translation:   ->   <-";
	str4 = "Color change:   C   V";
	mlx_string_put(tree->mlx_ptr, tree->win_ptr, 50, 50, 0xC0C0C0, str1);
	mlx_string_put(tree->mlx_ptr, tree->win_ptr, 50, 80, 0xC0C0C0, str2);
	mlx_string_put(tree->mlx_ptr, tree->win_ptr, 50, 110, 0xC0C0C0, str3);
	mlx_string_put(tree->mlx_ptr, tree->win_ptr, 50, 140, 0xC0C0C0, str4);
}

void		d_presskey(t_drag *dragon)
{
	char	*str1;
	char	*str2;
	char	*str3;
	char	*str4;

	str1 = "Leave:   esc";
	str2 = "Scale:   mouse scroll";
	str3 = "Translation:   ->   <-";
	str4 = "Color change:   C   V";
	mlx_string_put(dragon->mlx_ptr, dragon->win_ptr, 50, 50, 0xC0C0C0, str1);
	mlx_string_put(dragon->mlx_ptr, dragon->win_ptr, 50, 80, 0xC0C0C0, str2);
	mlx_string_put(dragon->mlx_ptr, dragon->win_ptr, 50, 110, 0xC0C0C0, str3);
	mlx_string_put(dragon->mlx_ptr, dragon->win_ptr, 50, 140, 0xC0C0C0, str4);
}
