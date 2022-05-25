/* ********************************************************************* */
/*          .-.                                                          */
/*    __   /   \   __                                                    */
/*   (  `'.\   /.'`  )   Tech-sland - Unlimited.cpp                      */
/*    '-._.(;;;)._.-'                                                    */
/*    .-'  ,`"`,  '-.                                                    */
/*   (__.-'/   \'-.__)   BY: Rosie (https://github.com/BlankRose)        */
/*       //\   /         Last Updated: Wed May 25 21:10:29 CEST 2022     */
/*      ||  '-'                                                          */
/* ********************************************************************* */

#include "Unlimited.hpp"

static int		value_length(unsigned int x)
{
	size_t	i;

	i = 1;
	while (x > 9)
	{
		x /= 10;
		i++;
	}
	return (i);
}

Unlimited::Unlimited()
{
	this->value = new char;
	this->value[0] = 0;
	this->isNeg = false;
}

Unlimited::Unlimited(int value)
{
	if (value < 0)
		this->isNeg = true;

	if (value == -__INT_MAX__ - 1) {
		this->value = new char[10];
		for (int i = 0; value < -9; i++) {
			this->value[i] = value % 10;
			value /= 10;
		}
	}

	else {
		this->value = new char[value_length(value)];
	}
}

Unlimited::~Unlimited()
{
	delete this->value;
}