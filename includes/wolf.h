#ifndef WOLF_H
# define WOLF_H

# include "libft.h"
# include "mlx.h"
# include "key_mapping.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAP_WIDTH	8
# define MAP_HEIGTH	8

/*
** Game constraint
**		FOV - Field Of View
**		BLOCK_SIZE - For each element in map
*/

# define FOV			60
# define SCREEN_HEIGTH	900
# define SCREEN_WIDTH	1600
# define BLOCK_SIZE		64

/*
** Colors
*/

# define SKY			0xCDE5FC
# define FLOOR			0xFFCC99

/*
** Game parameters
*/

# define PP_DIMENSION	SCREEN_WIDTH * SCREEN_HEIGTH
# define PP_CENTER		pp_center();
# define PP_DISTANCE	(SCREEN_WIDTH / 2) / tan(FOV / 2)
# define PP_UNIT		FOV / SCREEN_WIDTH

typedef struct		s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct		s_player
{
	t_vector		position;
	t_vector		camera;
}					t_player;

typedef struct		s_game
{
	void			*mlx;
	void			*window;
	void			*image;
	unsigned int	*pixels;
	t_player		bob;
}					t_game;

void				game_init(t_game game);
void				put_background(t_game game, size_t size);
void				put_pixel(t_game game, t_vector p, int color);
void				put_line(t_game game, t_vector p, size_t size, int color);

#endif /* !WOLF_H */

/* EOF */
