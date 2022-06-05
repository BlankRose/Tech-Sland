/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - graphics.hpp                       */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun  5 18:03:22 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __GRAPHICS_HPP__
# define __GRAPHICS_HPP__

#include "../classes/classes.hpp"
#include "../../MLX42/include/MLX42/MLX42.h"

#ifndef WIDTH
# define WIDTH 1280
#endif

#ifndef HEIGHT
# define HEIGHT 720
#endif

class Map;
class Player;

typedef struct s_game {
	mlx_image_t		*frame;
	mlx_image_t		*next;
	mlx_t			*mlx;

	Player			*player;
	Map				*map;
}	t_game;

void	mlx_handler(void);

#endif