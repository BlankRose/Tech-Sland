/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Entity.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun 12 18:33:57 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __ENTITY_HPP__
# define __ENTITY_HPP__

#include <string>
#include <iostream>
#include <cmath>

#define ENTITY_UNDEFINIED 0U

enum Direction
{
	NORTH = 1,
	SOUTH = 2,
	WEST = 3,
	EAST = 4,
};

class Entity
{
	private:
		//////// PRIVATE FUNCTIONS /////////

		Direction		getDir(int x, int y, float dx, float dy);

	protected:
		//////////// VARIABLES /////////////

		std::string		name;
		const size_t	id;

		Direction		dir;
		float			dx, dy;
		int				x, y;

	public:
		/////////// CONSTRUCTORS ///////////

		virtual ~Entity() = 0;

		Entity();
		Entity(const size_t&);
		Entity(const std::string&, const size_t&);
		Entity(const Entity&);

		//////////// OPERATORS /////////////

		Entity		&operator=(const Entity&);

		//////////// GET & SET /////////////

		std::string		getName(void) const;
		size_t			getID(void) const;
		Direction		getDir(void) const;
		float			getDX(void) const;
		float			getDY(void) const;
		int				getX(void) const;
		int				getY(void) const;

		//////////// FUNCTIONS /////////////

		void	movePos(int x, int y, float dx, float dy);
		void	setPos(int x, int y, float dx, float dy);
		void	lookAt(Direction dir);
};

#endif