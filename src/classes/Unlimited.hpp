/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Unlimited.hpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed May 25 20:10:42 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#ifndef __UNLIMITED_HPP__
# define __UNLIMITED_HPP__

#include "classes.h"
using namespace std;

class Unlimited
{
	private:
		char	*value;
		bool	isNeg;

	public:
		// Constructors
		Unlimited();
		Unlimited(int value);
		// Unlimited(long value);
		// Unlimited(float value);
		// Unlimited(double value);
		// Unlimited(string value);
		// Unlimited(char *value);
		Unlimited(Unlimited &v);

		// Destructors
		~Unlimited();
};

#endif