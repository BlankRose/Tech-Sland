/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - header.h                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun 19 00:08:12 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __HEADER_HPP__
# define __HEADER_HPP__

#include "../MLX42/include/MLX42/MLX42.h"
#include "classes/classes.h"

#include <algorithm>
#include <vector>

typedef unsigned char	t_byte;

typedef struct s_framework {
	mlx_t			*mlx;
	mlx_texture_t	*font;
	mlx_image_t		**frames;
	Time			*delay;
	size_t			count;
	t_byte			flags;
}	t_frame;

typedef struct s_data {
	t_frame		*frame;
	Player		*player;
}	t_data;

#define WINDOW_WIDTH 1366
#define WINDOW_HEIGHT 768

#define FONT_WIDTH 10
#define FONT_HEIGHT 20

void	ts_framework(t_data*);

int	ts_getPixel(const mlx_texture_t *texture, int x, int y);
void	ts_draw(mlx_image_t *frame, const mlx_texture_t *pack, int x, int y, int dx, int dy, int w, int h);
void	ts_write(mlx_image_t *frame, const mlx_texture_t *font, const std::string &string, int x, int y);
void	ts_write(mlx_image_t *frame, const mlx_texture_t *font, const char *string, int x, int y);

#endif