/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - header.h                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun 12 20:03:42 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __HEADER_HPP__
# define __HEADER_HPP__

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include "classes/classes.h"

#include <ctime>
#include <sys/time.h>
#include <algorithm>
#include <vector>

typedef unsigned char	t_byte;
typedef struct timeval	t_timeval;

typedef struct s_framework {
	mlx_t						*mlx;
	mlx_image_t					*frame;
	t_timeval					lastFrame;
	size_t						count;
	t_byte						flags;
}	t_frame;

typedef struct s_data {
	t_frame		*frame;
	Player		*player;
}	t_data;

#define WIDTH_DEFAULT 1366
#define HEIGHT_DEFAULT 768

void	ts_framework(t_data *data);

#endif