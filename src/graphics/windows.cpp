/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - windows.cpp                        */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun  5 18:14:01 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "graphics.hpp"

static void		mlx_key_handler(mlx_key_data key, void *data)
{
	t_game	*runtime = (t_game*) data;

	if (key.key == MLX_KEY_ESCAPE)
		mlx_close_window(runtime->mlx);
}

static void		mlx_loop_handler(void *data)
{
	t_game	*runtime = (t_game*) data;
	runtime = 0;
}

void	mlx_handler(void)
{
	t_game	*runtime = new t_game;
	runtime->mlx = mlx_init(WIDTH, HEIGHT, "Tech-Sland", false);
	runtime->player = new Player();
	runtime->map = new Map();

	mlx_key_hook(runtime->mlx, mlx_key_handler, runtime);
	mlx_loop_hook(runtime->mlx, mlx_loop_handler, runtime);
	mlx_loop(runtime->mlx);
	mlx_terminate(runtime->mlx);
}