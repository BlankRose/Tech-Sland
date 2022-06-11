/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - header.h                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Jun 11 17:43:37 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __HEADER_HPP__
# define __HEADER_HPP__

#include "../MLX42/include/MLX42/MLX42.h"
#include "../libft/libft.h"
#include <iostream>

typedef struct s_framework {
	mlx_t			*mlx;
	mlx_image_t		*frame;
}	t_frame;

typedef struct s_player {
	int		x;
	int		y;
}	t_ply;

typedef struct s_data {
	t_frame		*frame;
	t_ply		*player;
}	t_data;

#define WIDTH_DEFAULT 1366
#define HEIGHT_DEFAULT 768

#endif