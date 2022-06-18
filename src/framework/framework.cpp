/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - framework.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun 19 00:34:07 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "../header.h"

static void		ts_display_debug(mlx_image_t *img, t_data *data)
{
	/* Getting some references */
	t_frame			*frame = data->frame;
	mlx_texture_t	*font = frame->font;
	Player			*player = data->player;

	/* Prints player's position */
	ts_write(img, font, "Position:", 10, 10);
	ts_write(img, font, std::to_string(player->getX()), 120, 10);
	ts_write(img, font, std::to_string(player->getY()), 160, 10);

	/* Prints frames details */
	ts_write(img, font, "Frames:", 10, 30);
	long FrameSecond = static_cast<long> (1 / frame->delay->hasElapsed(Time::SYSTEM).totalSec());
	ts_write(img, font, std::to_string(FrameSecond), 120, 30);
	ts_write(img, font, std::to_string(frame->count), 160, 30);
}

static void		ts_new_frame(void *param)
{
	/* Getting some references */
	t_data		*data = static_cast<t_data*> (param);
	t_frame		*display = data->frame;
	mlx_t		*mlx = display->mlx;

	/* Select next frame to draw into and creates it before hand if it doesnt exists yet */
	if (!display->frames[display->count % 2]) {
		display->frames[display->count % 2] = mlx_new_image(mlx, mlx->width, mlx->height);
		mlx_image_to_window(mlx, display->frames[display->count % 2], 0, 0);
		mlx_set_instance_depth(display->frames[display->count % 2]->instances, 0);
	}
	mlx_image_t	*frame = display->frames[display->count % 2];

	/* Draw on the new frame */
	for (int x = 0; x < mlx->width; x++) {
		for (int y = 0; y < mlx->height; y++) {
			mlx_put_pixel(frame, x, y, 0x000050FF);
	}}
	if (data->frame->flags & 1) ts_display_debug(frame, data);

	/* Displays the image */
	display->frames[display->count % 2]->enabled = true;
	if (display->frames[(display->count + 1) % 2])
		display->frames[(display->count + 1) % 2]->enabled = false;

	/* Update the framework structure accordingly */
	if (display->count >= __UINT32_MAX__)
		display->count = 0;
	display->count++;
	display->delay->setTimeNow();
}

static void		ts_key_handler(mlx_key_data_t key, void *param)
{
	/* Completing the void* type comming from hook */
	t_data	*data = static_cast<t_data*> (param);

	/* Prevents from triggering twice from
	press and un-press actions */
	if (!key.action) return ;

	/* Sets Keybindings to their respective actions */
	switch (key.key) {
		/* Closes Frame */
		case MLX_KEY_ESCAPE:
			mlx_close_window(data->frame->mlx);
			break ;

		/* Up Movement */
		case MLX_KEY_UP:
		case MLX_KEY_W:
			data->player->movePos(0, 1, 0, 0);
			break ;

		/* Down Movement */
		case MLX_KEY_DOWN:
		case MLX_KEY_S:
			data->player->movePos(0, -1, 0, 0);
			break ;

		/* Right Movement */
		case MLX_KEY_RIGHT:
		case MLX_KEY_D:
			data->player->movePos(1, 0, 0, 0);
			break ;

		/* Left Movement */
		case MLX_KEY_LEFT:
		case MLX_KEY_A:
			data->player->movePos(-1, 0, 0, 0);
			break ;

		/* Debug Mode */
		case MLX_KEY_Q:
			data->frame->flags ^= 1;
			break ;

		/* Others will do nothing */
		default:
			break ;
	}
}

void		ts_framework(t_data *data)
{
	mlx_t	*mlx = data->frame->mlx;

	mlx_key_hook(mlx, ts_key_handler, data);
	mlx_loop_hook(mlx, ts_new_frame, data);
	mlx_loop(mlx);
}