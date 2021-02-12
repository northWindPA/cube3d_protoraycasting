/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhumfrey <mhumfrey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:44:17 by mhumfrey          #+#    #+#             */
/*   Updated: 2021/02/12 19:29:40 by mhumfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "./libft/libft.h"
# include "./minilibx/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

typedef struct	s_prc
{
	char		*l;
	int			n_l;
	int			fd;
	double		s_w;
	double		s_h;
	int			pl_f;
}				t_prc;

typedef struct	s_m
{
	char		**m;
	char		*n;
	char		*s;
	char		*w;
	char		*e;
	char		*sp;
	int			f;
	int			c;
}				t_m;

typedef struct	s_d
{
	void		*img;
	char		*add;
	int			bpp;
	int			l_l;
	int			endi;
	void		*mlx;
	void		*win;
}				t_d;

typedef struct	s_pl
{
	double		ps_x;
	double		ps_y;
	double		dr_x;
	double		dr_y;
	double		pln_x;
	double		pln_y;
	double		prv_ps_x;
	double		prv_ps_y;
}				t_pl;

typedef struct	s_mv_f
{
	int			mv_f;
	int			mv_b;
	int			mv_l;
	int			mv_r;
	int			rtt_l;
	int			rtt_r;
	int			spd_up;
}				t_mv_f;

typedef struct	s_r
{
	int			m_x;
	int			m_y;
	int			st_x;
	int			st_y;
	int			side;
	double		dlt_d_x;
	double		dlt_d_y;
	int			l_h;
	int			start;
	int			end;
	double		cmr;
	double		r_dr_x;
	double		r_dr_y;
	int			n_p_l;
	int			hit;
	double		mvspd;
	double		prv_dr_x;
	double		prv_pln_x;
	double		rtspd;
	double		sd_dst_x;
	double		sd_dst_y;
	double		prp_w_dst;
}				t_r;

typedef struct	s_tx
{
	int			tx_h[5];
	int			tx_w[5];
	double		w_x;
	int			tx_x;
	int			tx_y;
	double		tx_ps;
	double		stp;
}				t_tx;

typedef struct	s_tx_d
{
	void		*img;
	char		*add;
	int			bpp;
	int			l_l;
	int			endi;
}				t_tx_d;

typedef struct	s_sp
{
	double		sp_x;
	double		sp_y;
	double		invdt;
	double		dpth_x;
	double		dpth_y;
	int			ps_on_s;
	int			sp_h;
	int			sp_w;
	int			start_y;
	int			end_y;
	int			start_x;
	int			end_x;
	int			**sp;
	int			l_l;
	int			tx_x;
	int			tx_y;
	int			n_sp;
}				t_sp;

typedef struct	s_scrnst
{
	int				flag;
	int				fd;
	unsigned int	size;
	signed int		sign_z;
	unsigned int	unsi_z;
	unsigned int	ppd_54;
	unsigned int	ppd_40;
	unsigned int	pln_1;
}				t_scrnst;

typedef struct	s_f
{
	int			f_r;
	int			f_f;
	int			f_c;

}				t_f;

typedef struct	s_a
{
	t_prc		prc;
	t_m			m;
	t_f			f;
	t_d			d;
	t_r			r;
	t_pl		pl;
	t_tx		tx;
	t_tx_d		tx_d[5];
	t_mv_f		mv_f;
	t_sp		sp;
	t_scrnst	scrnst;
}				t_a;

int				error(char *st);
void			free_arr(char **arr);
int				loop_digit(char *pr);
void			my_pixel_put(t_a *a, int x, int y, int color);
unsigned int	texture_color(t_a *a, int x, int y, int cardinal_point);

void			right(t_a *a);
void			left(t_a *a);
void			forward(t_a *a);
void			back(t_a *a);
void			rotate_left(t_a *a);
void			rotate_right(t_a *a);
int				escape(t_a *a);
void			displacement(t_a *a);
int				unpressed(int key, t_a *a);
int				pressed(int key, t_a *a);

void			raycast_initiation(t_a *a);
void			raycast_correction(t_a *a);
void			hit_identification(t_a *a);
void			side_identification(t_a *a);

int				get_resolution(t_a *a, char **words);
int				parse_textures(t_a *a, char **words);
int				number_words(char **words);
int				parse_fc(t_a *a, char **words);
int				parse_floor(t_a *a, char **rgb);
int				parse_ceiling(t_a *a, char **rgb);
int				get_parameters(char *line, t_a *a);

int				spaces_line(char *line);
int				check_line(t_a *a, int x, int y);
void			player_dir(t_a *a, char direction, int x, int y);
int				validate_map(t_a *a);
int				validate_player(t_a *a, int x, int y);
char			**make_map(t_list **head, int size, t_a *a);
int				validate_line(char *line);
char			**read_map(t_a *a, char *line);

int				number_sprites(t_a *a);
int				**sprites_coordinates(t_a *a);
double			get_distance(t_a *a, int j);
void			sprites_srt(int amount, t_a *a);
void			sprites_proc(t_a *a, int i);
void			sprites_correction(t_a *a);
void			sprites_line(t_a *a);
void			draw_sprites(t_a *a, double *buffer_w);

int				take_side(t_a *a);
void			get_data_tex(t_a *a);
void			line_height(t_a *a);
void			texture_wall(t_a *a, int iterator);
void			floor_ceiling(t_a *a, int start, int end, int width);

int				get_screenshot(t_a *a);
void			bmp_head(t_a *a, int h, int w);

int				cube(t_a *a);
int				maze(t_a *a);

#endif
