/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - main.cpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sat Jun 11 17:48:03 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "header.h"
#include <stdlib.h>

static t_data	*ts_init_all(void)
{
	t_data	*data = new t_data;

	/* Initialize MLX */
	data->frame = new t_frame;
	data->frame->mlx = mlx_init(WIDTH_DEFAULT, HEIGHT_DEFAULT, "Tech-Sland", false);
	data->frame->frame = nullptr;

	/* Initialize Player */
	data->player = new t_ply;
	data->player->x = 0;
	data->player->y = 0;

	return (data);
}

static void		ts_new_frame(void *param)
{
	t_data		*data = (t_data*) param;
	mlx_t		*mlx = data->frame->mlx;

	mlx_image_t	*oldFrame = data->frame->frame;
	mlx_image_t	*newFrame = mlx_new_image(mlx, mlx->width, mlx->height);

	mlx_put_string(mlx, "Position:", 10, 10);
	mlx_put_string(mlx, ft_itoa(data->player->x), 10, 20);
	mlx_put_string(mlx, ft_itoa(data->player->y), 10, 30);

	if (oldFrame)
		mlx_delete_image(mlx, oldFrame);
	data->frame->frame = newFrame;
}

static void		ts_key_handler(mlx_key_data_t key, void *param)
{
	t_data	*data = (t_data*) param;

	if (!key.action) return ;

	switch (key.key) {
		case MLX_KEY_ESCAPE:
			mlx_close_window(data->frame->mlx);
			break ;

		case MLX_KEY_UP:
		case MLX_KEY_W:
			data->player->y++;
			break ;

		case MLX_KEY_DOWN:
		case MLX_KEY_S:
			data->player->y--;
			break ;

		case MLX_KEY_RIGHT:
		case MLX_KEY_D:
			data->player->x++;
			break ;

		case MLX_KEY_LEFT:
		case MLX_KEY_A:
			data->player->x--;
			break ;

		default:
			break ;
	}
}

int		main(void)
{
	t_data	*data = ts_init_all();
	mlx_t	*mlx = data->frame->mlx;

	mlx_key_hook(mlx, ts_key_handler, data);
	mlx_loop_hook(mlx, ts_new_frame, data);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}