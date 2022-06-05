/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Map.cpp                            */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun  5 18:13:28 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Map.hpp"

/* ****************************************************** */
/*                                                        */
/*                      CONSTRUCTORS                      */
/* Functions called when creating or destroying an object */
/*                                                        */
/* ****************************************************** */

Map::Map()
{
	this->ground = mlx_load_png(std::string(TEXTURES_PATH + std::string("grass.png")).data());
	this->water = mlx_load_png(std::string(TEXTURES_PATH + std::string("water.png")).data());
	this->sand = 0;
}

Map::Map(const std::string &path)
{
	this->ground = mlx_load_png(std::string(TEXTURES_PATH + std::string("grass.png")).data());
	this->water = mlx_load_png(std::string(TEXTURES_PATH + std::string("water.png")).data());
	this->sand = 0;

	std::ifstream	f(path, std::ios::out);
	if (!f.is_open()) throw FailedOpenFile();

	std::string		line;
	while (std::getline(f, line)) {
		this->map.push_back(line);
	}

	f.close();
}

Map::~Map()
{
	mlx_delete_texture(this->ground);
	mlx_delete_texture(this->water);
}

/* ****************************************************** */
/*                                                        */
/*                   OPERATORS OVERLOAD                   */
/*          Functions for overloading operators           */
/*                                                        */
/* ****************************************************** */

/* ****************************************************** */
/*                                                        */
/*                    MEMBER FUNCTIONS                    */
/* Declarations of member functions ready to use anywhere */
/*                                                        */
/* ****************************************************** */