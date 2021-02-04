/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarron <sdarron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 20:32:16 by sdarron           #+#    #+#             */
/*   Updated: 2020/02/16 21:14:56 by sdarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct	s_note
{
	int			colorstep;
	double		scale;
	int			c;
	int			colorgor;
	double		x;
	double		y;
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*nm;
}				t_mand;

typedef struct	s_jnote
{
	double		cr;
	double		ci;
	double		zr;
	double		zi;
	double		tmp;
	int			colorstep;
	double		scale;
	int			color;
	int			colorgor;
	double		crawlx;
	double		crawly;
	double		mousx;
	double		mousy;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*nj;
}				t_julia;

typedef struct	s_tnote
{
	double		scale;
	int			color;
	int			colorgor;
	double		crawlx;
	double		crawly;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*nt;
	double		windr;
	double		windl;
}				t_tree;

typedef struct	s_dnote
{
	double		n;
	double		scale;
	int			color;
	int			colorgor;
	double		crawlx;
	double		crawly;
	double		xc;
	double		yc;
	void		*mlx_ptr;
	void		*win_ptr;
	char		*nd;
}				t_drag;

void			drawmandel(t_mand *mandel);
int				deal_key(int key, t_mand *mandel);
int				mouse_release(int button, int x, int y, t_mand *mandel);
int				j_mouse_release(int button, int x, int y, t_julia *julia);
void			drawjulia(t_julia *julia);
void			drawtree(double xy[2], double l, double a, t_tree *tree);
int				tr_mouse_release(int button, int x, int y, t_tree *tree);
int				mouse_move(int x, int y, t_julia *julia);
int				hook_mousemove(int x, int y, t_julia *julia);
void			ft_mandel(t_mand *mandel);
void			ft_julia(t_julia *julia);
void			ft_tree(t_tree *tree);
void			ft_dragon(t_drag *drag);
void			drdr(double xyx1y1[4], int n, t_drag *drag);
double			maxim(double a, double b);
double			mod(double i);
void			pixmand(int j, int i, t_mand *m);
int				cinumb(t_mand *mandel);
void			dpixel(double xx1[2], double y, double y1, t_drag *drag);
void			pixel(double xx1[2], double y, double y1, t_tree *tree);
int				d_mouse_release(int button, int x, int y, t_drag *drag);
int				m_deal_key(int key, t_mand *mandel);
int				j_deal_key(int key, t_julia *julia);
int				t_deal_key(int key, t_tree *tree);
int				d_deal_key(int key, t_drag *drag);
void			juliapix(int l, int i, t_julia *j);
int				hook_mousemove(int x, int y, t_julia *julia);
void			d_deal_key1(int key, t_drag *drag);
void			name(t_mand *mand, t_julia *jul, t_tree *tree, t_drag *drag);
int				frafree(t_mand *m, t_julia *j, t_tree *t, t_drag *d);
int				ft_select(char *select);
void			validfract(char *av[1], t_mand *m, t_julia *j, t_tree *t);
void			formdrag(double *pixx1, double y, double y1, t_drag *drag);
void			m_presskey(t_mand *mandel);
void			j_presskey(t_julia *julia);
void			t_presskey(t_tree *tree);
void			d_presskey(t_drag *dragon);
int				t_hook_mousemove(int x, int y, t_tree *tree);
void			m_pthread(t_mand *m);

#endif
