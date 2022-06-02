/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Player.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed Jun  1 22:27:48 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include "classes.hpp"

class Player
{
	private:
		std::string	name;
		int			health;
		int			mana;
		int			attack;
		int			defense;
		int			economy;
	
	public:
		Player();
		~Player();
};

#endif