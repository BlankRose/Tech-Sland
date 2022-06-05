/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Map.hpp                            */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun  5 18:11:39 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __MAP_HPP__
# define __MAP_HPP__

#include "classes.hpp"
#include "../../MLX42/include/MLX42/MLX42.h"

#ifndef TEXTURES_PATH
# define TEXTURES_PATH "./data/assets/"
#endif

#ifndef MAPS_PATH
# define MAPS_PATH "./data/maps/"
#endif

/* MAP CLASS:
 *
 * A class which handles the mapping of the game overall
 * from loading to saving those.
 */
class Map
{
	private:
		std::vector<std::string>	map;
		mlx_texture_t				*ground;
		mlx_texture_t				*water;
		mlx_texture_t				*sand;

	public:
		Map();
		Map(const std::string&);
		Map(const Map&);
		~Map();

		class FailedOpenFile: std::exception
		{
			public:
				virtual const char *what() const throw()
					{return "Couldn't open file";}
		};
};

#endif