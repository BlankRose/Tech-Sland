/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Player.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed May 25 19:34:34 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include "classes.h"
using namespace std;

class Player
{
	private:
		string		name;
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