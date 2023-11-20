/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub69d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aikram <aikram@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 13:51:27 by aikram            #+#    #+#             */
/*   Updated: 2023/11/20 21:13:59 by aikram           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB69D_H
# define CUB69D_H

# include <stdint.h>
# include "parse.h"

# define PIW 3.1415926536
# define PIE (PIW * 2)
# define PIN (PIW / 2)
# define PIS ((3 * PIW) / 2)

# define WIDTH 2250
# define HEIGHT 1250
# define TEXDIM 256


# define DARK_BLUE 0x00000032
# define DARK_BROWN 0x00320000
# define DARK_PRL_PNK 0x006c2545
# define MATURE_GREEN 0x00afb7aa
# define MATURE_SKY 0x00324232

typedef struct s_cords {
	double	x;
	double	y;
}				t_cords;

typedef struct	s_img {
	void	*img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		wdth;
	int		hght;
}				t_img;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	t_img	*img;
}				t_mlx;

typedef struct s_plr {
	t_cords	pos;
	t_cords	dir;
	double	mv_spd;
	double	rt_spd;
}				t_plr;

typedef struct s_texture {
	int			id;
	t_icords	crd;
	size_t		color;
	double		pos;
	double		step;
	int			line_hgt;
	int			draw_start;
	int			draw_end;
	struct s_texture *poopy;
} t_rex;

typedef struct s_ray {
	t_cords		dir;
	t_cords		side_dist;
	t_cords		delta_dist;
	t_icords	map;
	t_icords	step;
	int			hit;
	int			side;
	double		perp_wall_dist;
}				t_ray;

typedef struct	s_frame {
	int		chnge;
	int		step;
	size_t	**frmes;
	char	*fpth[3];
}				t_frame;

typedef struct	s_table {
	bool		keys[6];
	bool		destroy;
	char	*swen_pth[4];
	size_t	**swen_tx;
	t_plr		plr;
	t_ray		ray;
	t_rex		tex;
	t_mlx		mlx;
	t_cords		plane;
	t_parse		*parse;
	t_frame		frame;
	t_icords	map_max;

	double		camx;
	int			col;
}				t_able;

bool	free_table(t_able *table);
int	ultimate_destroyer(t_able *table);

void	texture_path_match(t_able *table);

char	*ft_strdup(const char *s1);
int		main_loop(t_able *table);
void	annihilate_img(t_mlx *mlx_ptr);
int		key_press(int key, t_able *table);
bool	create_new_image(t_mlx *mlx_ptr, bool destroy);
t_img	*new_image(t_able *table, bool destroy);

void	fill_image(t_img *data, int x, int y, int color);
void	calc(t_able *table);

bool	init_texture(t_able *table);
void	texture(t_able *table);

int		handle_keyrelease(int keysym, t_able *table);
int		handle_keypress(int keysym, t_able *table);

void	draw_column(t_able *table);
void	fill_col_clr(t_able *table);

void	fill_frm_col(t_able *table);
bool	load_texture(t_able *table, size_t *tex, char *path);


int eggsecute(t_parse *parse);

/* movement */
void	plyr_rt(t_able *table);
void	plyr_rrt(t_able *table);
void	plyr_mvment(t_able *table, int forward);
void	plyr_strafe(t_able *table, int right);

/* movement_director */
void	plyr_rt_and_mv(t_able *table, int rt, int mv);
void	plyr_rt_and_strf(t_able *table, int rt, int strf);
void	strafe_and_move(t_able *table, int mv, int strf);
void	mv_strf_rt(t_able *table, int mv, int strf, int rt);

/* movement_handler */
bool	handle_movements_util0(t_able *table);
bool	handle_movements_util1(t_able *table);
void	handle_movements(t_able *table);

/* events */
int		handle_keypress(int keysym, t_able *table);
int		handle_keyrelease(int keysym, t_able *table);
int		main_loop(t_able *table);

# endif