/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Player.hpp                         */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Sun Jun  5 18:40:43 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __PLAYER_HPP__
# define __PLAYER_HPP__

#include "classes.hpp"

/* PLAYER CLASS:
 * 
 * An class to represent any players within the game.
 * Not much to say about it ngl...
 */
class Player
{
	private:
		const std::string	name;
		size_t				health;
		size_t				attack;
		size_t				defense;
		double				economy;

		double		X;
		double		Y;

	public:
		Player();
		Player(const Player&);
		~Player();

		Player		&operator=(const Player&);

		double		getX(void);
		double		getY(void);
		std::string	getName(void);
		size_t		getHealth(void);
		size_t		getAttack(void);
		size_t		getDefense(void);
		double		getEconomy(void);

		double		getX(void) const;
		double		getY(void) const;
		std::string	getName(void) const;
		size_t		getHealth(void) const;
		size_t		getAttack(void) const;
		size_t		getDefense(void) const;
		double		getEconomy(void) const;

		void		setX(double);
		void		setY(double);
		void		setHealth(size_t);
		void		setAttack(size_t);
		void		setDefense(size_t);
		void		setEconomy(double);
		void		setPos(double, double);
};

#endif