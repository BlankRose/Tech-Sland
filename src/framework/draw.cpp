/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - draw.cpp                           */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun 19 00:00:30 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "../header.h"

/**
 * Get the pixel full value located within a texture
 * 
 * @param[in]	texture: Texture to find the given pixel
 * @param[in]	x_y: Position X and Y of the pixel
 * 
 * @return		Pixel's color value
 **/
int		ts_getPixel(const mlx_texture_t *text, int x, int y)
{
	/* Protect in case text is unspecified or invalid x, y values */
	if (!text || x < 0 || y < 0)
		return (0x0);

	/* Find pixel within texture data */
	uint8_t		*target =
		&text->pixels [(y * text->width * text->bytes_per_pixel)
		+ (x * text->bytes_per_pixel)];

	/* Fetch the pixel values and return it */
	int		pixel = 0x0;
	for (size_t i = 0; i < 4; i++)
		pixel = (pixel * 256) + target[i];

	return (pixel);
}

/**
 * Draws a texture area with given position and size and
 * draw it on the image
 *
 * @param[in]	frame: Image to draw onto
 * @param[in]	pack: Tileset where to take from region
 * @param[in]	x_y: Position X and Y of first pixel
 * @param[in]	dx_dy: Position X and Y of region first pixel
 * @param[in]	w_h: Width and Height of region to draw
 **/
void	ts_draw(mlx_image_t *frame, const mlx_texture_t *pack,
			int x, int y, int dx, int dy, int w, int h)
{
	/* Prevent the function to run if any parameters is empty / null */
	if (!frame || !pack)
		return;

	/* Place down each pixels one after one on the frame */
	int color = 0x0;
	for (int px = 0; px < w; px++) {
		for (int py = 0; py < h; py++) {
			color = ts_getPixel(pack, px + dx * w, py + dy * h);
			if (color) mlx_put_pixel(frame, x + px, y + py, color);
	}}
}

/**
 * Write an string down on the given frame, using a font
 * as reference
 * 
 * @note		String variant
 * 
 * @param[in]	frame: Image to write onto
 * @param[in]	font: Font reference
 * @param[in]	string: Text to write down
 * @param[in]	x_y: Offset X and Y for the Text
 **/
void	ts_write(mlx_image_t *frame, const mlx_texture_t *font, const std::string &str, int x, int y)
{
	/* Prevent the function to run if any parameters is empty / null */
	if (!font || !frame || str.empty())
		return;

	/* Iterates over each characters and draw each chars onto the frame */
	unsigned char ref = 0;
	for (size_t i = 0; str[i]; i++) {

		/* Get ref and skips firsts non printable characters 
		OR Set ref to DEL character if its too high */
		ref = str[i] - 32;
		if (str[i] < 32) continue ;
		if (str[i] > 127) ref = 127;

		/* Place down pixel after pixels characters */
		ts_draw(frame, font, x + FONT_WIDTH * i, y, ref % 8, ref / 8, FONT_WIDTH, FONT_HEIGHT);
	}
}

/**
 * Write an string down on the given frame, using a font
 * as reference
 * 
 * @note		Char* Variant
 * 
 * @param[in]	frame: Image to write onto
 * @param[in]	font: Font reference
 * @param[in]	string: Text to write down
 * @param[in]	x_y: Offset X and Y for the Text
 **/
void	ts_write(mlx_image_t *frame, const mlx_texture_t *font, const char *str, int x, int y)
{
	ts_write(frame, font, std::string(str), x, y);
}