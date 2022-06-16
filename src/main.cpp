/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - main.cpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Thu Jun 16 14:04:20 CEST 2022     */
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
	gettimeofday(&data->frame->lastFrame, 0);
	data->frame->frame = nullptr;
	data->frame->flags = 0x0;
	data->frame->count = 0;

	/* Initialize Player */
	data->player = new Player("Rosie");

	return (data);
}

static int		ts_clear_all(t_data *data)
{
	delete	data->player;
	delete	data->frame;
	delete	data;

	return	0;
}

int		main(void)
{
	t_data	*data = ts_init_all();

	ts_framework(data);
	return ts_clear_all(data);
}