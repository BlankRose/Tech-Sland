/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Player.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun 12 18:33:50 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include "Entity.hpp"
#define ENTITY_PLAYER 1U

class Player: public Entity
{
	public:
		/////////// CONSTRUCTORS ///////////

		Player();
		Player(const std::string&);
		Player(const Player&);
		~Player();

		//////////// OPERATORS /////////////

		Player			&operator=(const Player&);
};

#endif